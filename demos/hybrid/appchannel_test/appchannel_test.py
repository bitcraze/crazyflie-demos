# -*- coding: utf-8 -*-
#
#     ||          ____  _ __
#  +------+      / __ )(_) /_______________ _____  ___
#  | 0xBC |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
#  +------+    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
#   ||  ||    /_____/_/\__/\___/_/   \__,_/ /___/\___/
#
#  Copyright (C) 2026 Bitcraze AB
#
#  This program is free software; you can redistribute it and/or
#  modify it under the terms of the GNU General Public License
#  as published by the Free Software Foundation; either version 2
#  of the License, or (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.
"""
Connects to the first Crazyflie found and sends/receives appchannel packets.

The protocol is:
 - 3 floats are sent: x, y, z
 - The Crazyflie sends back the sum as one float
"""
import logging
import struct
import time

import cflib.crtp
from cflib.crazyflie import Crazyflie
from cflib.crazyflie.syncCrazyflie import SyncCrazyflie

logging.basicConfig(level=logging.ERROR)

URI = 'radio://0/80/2M/E7E7E7E7E7'


def packet_received(data):
    (total,) = struct.unpack('<f', data)
    print(f'Received sum: {total}')


if __name__ == '__main__':
    cflib.crtp.init_drivers()
    print(f'Connecting to {URI}')
    with SyncCrazyflie(URI, cf=Crazyflie()) as scf:
        scf.cf.appchannel.packet_received.add_callback(packet_received)
        for i in range(10):
            x, y, z = i, i + 1, i + 2
            scf.cf.appchannel.send_packet(struct.pack('<fff', x, y, z))
            print(f'Sent x: {x}, y: {y}, z: {z}')
            time.sleep(1)
