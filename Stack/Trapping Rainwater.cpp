class Solution {
public:
    int trap(vector<int>& ht) {
        int n=ht.size();
        vector<int>lmax(n,0);
        vector<int>rmax(n,0);

        lmax[0]=ht[0];
        rmax[n-1]=ht[n-1];

        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],ht[i]);
        }

        for(int i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],ht[i]);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            ans+=min(lmax[i],rmax[i])-ht[i];
        }

        return ans;
    }
};


//two pointers approach

class Solution {
public:
    int trap(vector<int>& ht) {

        int n=ht.size();
        int l=0;
        int r=n-1;

        int lmax=0;
        int rmax=0;

        int ans=0;
       while(l<r){
        lmax=max(lmax,ht[l]);
        rmax=max(rmax,ht[r]);

        
        if(lmax<rmax){
            ans+=(lmax-ht[l]);
            l++;
        }
        else{
            ans+=(rmax-ht[r]);
            r--;
        }
       }
        return ans;
    }
};