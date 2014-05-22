#encode:utf-8

import os
import time

#timestring
ts = time.strftime("%y%m%d%H%M%S")
#backup
os.system("tar -jcv -f /var/www/syukumi"+ts+".tar.bz2 /var/www/html/dokuwiki")

