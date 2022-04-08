#!/bin/bash

./init-IMT2019012 &
./doc-IMT2019012 &
./visitor-IMT2019012 A B &
./visitor-IMT2019012 C &
./visitor-IMT2019012 D &
./visitor-IMT2019012 E &
./visitor-IMT2019012 F &
sleep 5
./visitor-IMT2019012 G &

sleep 7

sleep 10
./visitor-IMT2019012 H &
./visitor-IMT2019012 I &
./visitor-IMT2019012 J &
./visitor-IMT2019012 K &
./visitor-IMT2019012 L &
./visitor-IMT2019012 M &

sleep 9

sleep 10
./visitor-IMT2019012 N &
./visitor-IMT2019012 O &
./visitor-IMT2019012 P &
./visitor-IMT2019012 Q &
./visitor-IMT2019012 R &
sleep 2
./visitor-IMT2019012 S &
./visitor-IMT2019012 T &
./visitor-IMT2019012 U &

sleep 30
./visitor-IMT2019012 V &