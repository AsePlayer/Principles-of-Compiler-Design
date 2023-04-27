# append the current time to a text file
# Usage: python timer.py

import time
import datetime

# get the current time
now = datetime.datetime.now()

# open the file
f = open('timer.txt', 'a')

# write the current time to the file
f.write(str(now) + '\n')

# close the file
f.close()