#!/bin/zsh
###
 # @Author: Jack
 # @Date: 2023-10-29 12:12:15
 # @LastEditors: Jack
 # @LastEditTime: 2023-10-29 13:11:06
### 
make clean
flex snow.l
bison snow.y
make