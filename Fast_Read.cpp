inline int read() {
	register int ee=0;
	register bool ff=false;
	register char ch=getchar();
	while(!(ch>='0'&&ch<='9')) {
		if(ch=='-') ff=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		ee=(ee*10+ch-'0');
		ch=getchar();
	}
	return ff?-ee:ee;
}
