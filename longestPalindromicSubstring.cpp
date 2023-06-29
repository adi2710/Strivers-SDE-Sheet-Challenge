string longestPalinSubstring(string str)
{
    // Write your code here.
    int st = -1, len = 0, n = str.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; 0 <= i - j && i + j < n; j++)
        {
            if(str[i - j] == str[i + j])
            {
                if(2 * j + 1 > len)
                {
                    st = i - j;
                    len = 2 * j + 1;
                }
            }
            else
                break;
        }
        for(int j = 0; 0 <= i - j && i + j + 1 < n; j++)
        {
            if(str[i - j] == str[i + j + 1])
            {
                if(2 * j + 2 > len)
                {
                    st = i - j;
                    len = 2 * j + 2;
                }
            }
            else
                break;
        }
    }
    return str.substr(st, len);
}