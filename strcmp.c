short int Str_cmp(const char *s1, const char *s2)
{
    char i,n1,n2;
    n1= (sizeof(s1)/sizeof(s1[0]))-1;
    n2= (sizeof(s2)/sizeof(s2[0]))-1;
    if(n1>n2)
         return 1; 
   else
        {
              for(i=0 ; i<n1; i++)
              {
                       if(s1[i]>s2[i])
                            return 1;
                     else if(s1[i]<s2[i])
                            return -1;
                     else 
                            continue;                                   
               }
             return 0;
         }
}				