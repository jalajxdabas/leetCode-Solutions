class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = version1.length();
        int v2 = version2.length();

        int x1 = 0;
        int x2 = 0;

        for(int i=0, j=0; i < v1 || j< v2; i++,j++){
            while(i<v1 && version1[i] != '.'){
                x1 = 10*x1 + (version1[i] - '0');
                i++;
            }

            while(j<v2 && version2[j] != '.'){
                x2 = 10*x2 + (version2[j] - '0');
                j++;
            }

            if(x1 < x2) return -1;
            if(x1 > x2) return 1;

            x1 = 0;
            x2 = 0;
        }
        return 0;
    }
};