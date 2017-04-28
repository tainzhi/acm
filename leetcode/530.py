###############################################################################
# File        : 530.py
# Author      : tainzhi
# Mail        : qfq61@qq.com
# Created     : 2017-04-28 22:13:57
# Modified    : 2017-04-28 22:14:09
# Description : 
###############################################################################/


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.preview = -1
        self.min_val = -1
        def InOrderTraverse(root):
            if root != None:
                InOrderTraverse(root.left)
                if self.preview != -1:
                    if self.min_val == -1:
                        self.min_val = root.val - self.preview
                    else:
                        self.min_val = min(self.min_val, root.val - self.preview)
                self.preview = root.val
                InOrderTraverse(root.right)
        InOrderTraverse(root)
        return self.min_val
       
            
