import queue
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        output = []
        order = 0
        q = queue.Queue()
        q.put([root, 0])
        while not q.empty():
            now, order = q.get()
            if now is None: 
                continue
            if len(output) <= order:
                output.append([])
            output[order].append(now.val)
            q.put([now.left, order + 1])
            q.put([now.right, order + 1])

        for i in range(1, order, 2):
            output[i].reverse()
        return output
