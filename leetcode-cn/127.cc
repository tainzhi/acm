class Solution
{
public:
	// BFS
	int ladderLength1(string beginWord, string endWord, vector<string> &wordList)
	{
		unordered_set<string> set(wordList.begin(), wordList.end());
		if (set.find(endWord) == set.end())
			return 0;
		queue<string> que;
		que.push(beginWord);
		int step = 0;
		while (!que.empty())
		{
			int q_size = que.size();
			while (q_size-- > 0)
			{
				string cur = que.front();
				if (cur == endWord)
				{
					return step + 1;
				}
				que.pop();
				for (int i = 0; i < cur.size(); i++)
				{
					char original = cur[i];
					for (char c = 'a'; c <= 'z'; c++)
					{
						if (cur[i] == c)
							continue;
						cur[i] = c;
						if (set.find(cur) != set.end())
						{
							que.push(cur);
							set.erase(cur);
						}
					}
					cur[i] = original;
				}
			}
			step++;
		}
		return 0;
	}

	// two direction BFS
	int ladderLength(string beginWord, string endWord, vector<string> &wordList)
	{
		unordered_set<string> dict(wordList.begin(), wordList.end());
		// 没有找到
		if (dict.find(endWord) == dict.end())
			return 0;
		unordered_set<string> begin_set, end_set, visit, tmp;
		begin_set.insert(beginWord);
		end_set.insert(endWord);
		int step = 1;
		while (!begin_set.empty() && !end_set.empty())
		{
			// 因为是双向BFS, 同时从begin end开始遍历, 时间理论上市BFS的 1/2
			// 此处模拟: 先从begin遍历, 再从end开始遍历, 等效为同时开始遍历
			if (begin_set.size() > end_set.size())
			{
				tmp = begin_set;
				begin_set = end_set;
				end_set = tmp;
			}
			tmp.clear();
			for (string cur : begin_set)
			{
				for (int i = 0; i < cur.size(); i++)
				{
					char original = cur[i];
					for (char c = 'a'; c <= 'z'; c++)
					{
						if (cur[i] == c) continue;
						cur[i] = c;
						// 双向遍历到交点
						if (end_set.find(cur)!= end_set.end()) {
							return step +1;
						}
						// 没有visit到
						if (dict.find(cur) != dict.end() && visit.find(cur) == visit.end()) {
							tmp.insert(cur);
							visit.insert(cur);
						}
					}
					cur[i] = original;
				}
			}
			// 这一层可以遍历的路径尝试走完后, 清空
			// 填入刚才下一层的路径
			begin_set = tmp;
			step++;
		}
		return 0;
	}
};