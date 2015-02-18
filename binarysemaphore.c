int n;
binary_semaphore s=1, delay=0;
srruct binary_semaphore
{
	enum {zero,one} value; 
	queueType queue;
};
void semWaitB(binary_semaphore s)
{
	if(s.value==one)
		s.value=zero;
	else
	{
		s.queue=s;
		block();
	}
}
void semSignalB(binary_semaphore s)
{
	if(s.queue==NULL)
		s.value=one;
}		
void produce()
{
	n++;
}
void consume()
{
	n--;
}
void append()
{
	n++;
}
void take()
{
	n--;
}
void producer()
{
	while(true)
	{
		produce();
		semWaitB(s);
		append();
		n++;
		if(n==1)
			semSignalB(delay);
		semSignalB(s);
	}
}
void consumer()
{
	int m;
	semWaitB(delay);
	while(true)
	{
		semWaitB(s);
		take();
		n--;
		m=n;
		semSignalB(s);
		consume();
		if(m==0)
			semWaitB(delay);
	}
}
void main()
{
	n=0;
	producer();
	consumer();
}