
int main(){ int n; //LATEX_IGNORED_LINE

	// n / i has the same value for l <= i <= r
	
	for(int l=1, r; l<=n; l=r+1){  //O(sqrt(n))
		r = n / (n/l);             // n/l == n/r
	}

}//LATEX_IGNORED_LINE
