#ifndef _MY_UTIL_HPP_
#define _MY_UTIL_HPP_

#define ALL(a)     (a).begin(),(a).end()
#define EACH(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c)    sort((c).begin(),(c).end())
#define RSORT(c)    sort((c).rbegin(),(c).rend())
#define MAXINDEX(c) distance((c).begin(),max_element((c).begin(),(c).end()))
#define MININDEX(c) distance((c).begin(),min_element((c).begin(),(c).end()))
#define DEBUG(x)   std::cerr <<#x<<" = "<<(x)<<" ("<<__FILE__<<"::"<<__LINE__<<")"<<std::endl;
#define ERROR(s)   std::cerr <<"Error::"<<__FILE__<<"::"<<__LINE__<<"::"<<__FUNCTION__<<"::"<<(s)<<std::endl;
#define FOR(i,a,b) for (auto i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)


inline unsigned char *read_binary(char *filename,unsigned int *size){
    FILE *fp;
    if((fp = fopen(filename , "rb" ))==NULL){
        fprintf(stderr,"fopen FAILURE\n");
        exit(1);
    }
	fseek( fp, 0, SEEK_END );
	*size = ftell( fp );
	fseek( fp, 0, SEEK_SET );
	unsigned char *str=(unsigned char *)malloc(*size);
	int temp=fread(str,1,*size,fp);
    fclose(fp);
    return str;
}

inline unsigned char *read_ascii(char *filename,unsigned int *size){
    FILE *fp;
    if((fp = fopen(filename , "r" ))==NULL){
        fprintf(stderr,"fopen FAILURE\n");
        exit(1);
    }
	fseek( fp, 0, SEEK_END );
	*size = ftell( fp );
	fseek( fp, 0, SEEK_SET );
	unsigned char *str=(unsigned char *)malloc(*size);
	int temp=fread(str,1,*size,fp);
    fclose(fp);
    return str;
}


#endif
