int mult(int n,int m) {
	int temp=0;
	while (n != 1)
	{
		if (n % 2 == 0) {
			n /= 2;
			m *= 2;
		}
		else if (n % 2 == 1) {
			temp += m;
			m += m;
		}
	}
	m += temp;
	
	return  m;
}