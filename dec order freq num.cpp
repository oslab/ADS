 #include<stdio.h>
 int main(){
 char s[50];
 scanf("%s",s);
 int i,j,k,cnt[26]={0};
 for(i=0;s[i]!='\0';i++){
 cnt[s[i]-'a']++;}
 int max=0;
 for(i=0;i<26;i++){
 if(cnt[i]>max)
 max=cnt[i];}
 for(i=max;i>=0;i--){
 for(j=0;j<26;j++){
 if(cnt[j]==i){
 for(k=0;k<cnt[j];k++){
 printf("%c",j+'a');
 }}}}}
