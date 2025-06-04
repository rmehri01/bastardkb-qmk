#!/bin/bash
while true
do
  mount /dev/sda1 /mnt && cp bastardkb_skeletyl_rmehri01.uf2 /mnt && umount /mnt && echo 'done!' && exit
  sleep 1
done
