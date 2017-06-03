#!/usr/bin/env python##########################################################
# -*- coding: utf-8 -*-########################################################
# File        : 458.py
# Author      : tainzhi
# Mail        : qfq61@qq.com
# Created     : 2017-06-03 09:19:28
# Modified    : 2017-06-03 09:19:28
# Description :
# #############################################################################/

class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        """
        :type buckets: int
        :type minutesToDie: int
        :type minutesToTest: int
        :rtype: int
        """
        t = minutesToTest / minutesToDie + 1
        return int(math.ceil(math.log(buckets, t)))
