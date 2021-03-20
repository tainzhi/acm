class Solution {
public:
    bool isValide(int & nu) {
        return nu >= 0 && nu < (1<<8);
    }
    bool validUtf8(vector<int>& data) {
        int index = 0;
        while (index < data.size()) {
            int cur = data[index];
            if (!isValide(cur)) return false;
            if (cur & (1<<0x7)) {
                int cnt = 0;
                while ((cur >> (7 - cnt) & 0x1) == 0x1) {
                    ++cnt;
                    if (cnt > 3) return false;
                }
                for (int i = index+1; i < index + cnt; ++i) {
                    if (!isValide(data[i])) return false;
                    if (data[i] < (1 << 7) || data[i] > ((1<<7) + (1<<6) - 1)) return false;
                }
                index += cnt;

            } else {
                // 1 字节
                ++index;
            }
        }
        return true;
    }
};
