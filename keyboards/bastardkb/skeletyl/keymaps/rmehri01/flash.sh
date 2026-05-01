#!/bin/bash
make bastardkb/skeletyl/splinktegrated_rev1:rmehri01
while true
do
  mount /dev/sda1 /mnt && cp bastardkb_skeletyl_splinktegrated_rev1_rmehri01.uf2 /mnt && umount /mnt && echo 'done!' && exit
  sleep 1
done
