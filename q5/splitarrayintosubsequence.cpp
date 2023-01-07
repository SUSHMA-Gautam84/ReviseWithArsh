class Solution {
public:
bool isPossible(vector& nums) {
map<int,int>fm;
map<int,int>hm;
for(int i:nums){
fm[i]++;
}
for(int i:nums){
if(fm[i]==0)continue;
if(hm[i]>0){
hm[i]--;
hm[i+1]++;
fm[i]--;
}else if(fm[i]>0&&fm[i+1]>0&&fm[i+2]>0){
fm[i]--;
fm[i+1]--;
fm[i+2]--;
hm[i+3]++;
}else return false;
}
return true;
}
};
