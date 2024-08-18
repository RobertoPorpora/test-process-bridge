import sys
import os
import time

python_folder = os.path.dirname(os.path.abspath(__file__))
src_folder = os.path.dirname(python_folder)
root_folder = os.path.dirname(src_folder)
sys.path.insert(0, f'{root_folder}/lib/python_process_bridge/')
from process_bridge import ParentProcess

parent = ParentProcess();

buf = []
buf.append(parent.receive())
buf.append(parent.receive())
buf.append(parent.receive())

parent.send(f'c1 {buf[0]} {buf[1]} {buf[2]}')
parent.send_err(f'c1 {buf[0]} {buf[1]} {buf[2]}')
parent.send('c2')
parent.send_err('c2')
parent.send('c3')
parent.send_err('c3')

time.sleep(1.0)

sys.exit(12)
