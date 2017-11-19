// Subclasses for backend of MaxPool Layers
// Subclasses for fully_connected
// Size passed in operation functions is NXN
// Author: Suyash Nigam
  class Layer_3  //Maxpool Layer 3
  {
  	private:
    int c;
    int maxP; //Size of kernel
    int maxP_stride;
    int layer_flag;
    char info[500];

        public:
    Layer_3(); //Intitialize the data members
    void show(); //Calls the master function for showing arbitrary dimensional array
    int parameter(); //Return the parameters of a layer
    char* info(); 
    void operation(int [][]);
 



  };


  Layer_3::Layer_3()
  {
  	layer_flag=3
  	maxP=2;
  	maxP_stride=2;
  	c=16;
  	info="";


  }

  int Layer_3::parameter()
  {
  	return maxP;

  }

  char* Layer_3::info()
  {
  	return info;
  }

void Layer_3::operation(int Convu1[a][b],int size) 
  //Assumes a N^2 X c_previous output
  //In MaxP c-prev=c 

  {   
  	  n=int(sqrt(size));
  	  int channel[n][n];
  	  m=int(n/maxP);   
  	  int output[m*m][c];
  	  int output1[m*m]; 
  	  outputs
      for (auto i=1;i<=c;i++)
      {
        channel[n][n] = Get_matrix(Convu,n,c,i);
        j=0;
        while(auto j<n)
        	{   max=-1000;
        		output_m=0;
        		for (auto x=j;x<maxP_size;x++)
        		{
        			for (auto y=j;y<maxP;y++)
        			{
                      if(channel[x][y]>max)
                      {
                      	max=channel[x][y];
                      }
        			}
        		}
        		output1[output_m]=max;
        		output_m++;

        		j+=maxP_stride;

        	}

        	for(auto q=0;q<output_m;q++) 
        	{
              output[q][i]=output1[q];
        	}       
           


      }

    


  }

void Layer_3::show()
{
  c_show=[2,4,8]; // Arbitrary chossing arrays to show
  m=int(n/maxP);
  int out_show[m*m][3];
  for (auto i=0;i<m*m;i++) 
  {
  	for (auto j=0;j<3;j++)
  	{
  		out_show[i][j]=output[i][j];
  	}
  }  

  master_display(out_show); //Calling Sagar's function



}


// Subclasses for backend of MaxPool Layers
  class Layer_6  //Maxpool Layer 2
  {
  	private:
    int c;
    int maxP; //Size of kernel
    int maxP_stride;
    int layer_flag;
    char info[500];

        public:
    Layer_6(); //Intitialize the data members
    void show(); //Calls the master function for showing arbitrary dimensional array
    int parameter(); //Return the parameters of a layer
    char* info(); 
    void operation(int [][]);
 



  };


  Layer_6::Layer_6()
  {

  	layer_flag=6;
  	maxP=2;
  	maxP_stride=2;
  	c=32;
  	info="";


  }

  int Layer_6::parameter()
  {
  	return maxP;

  }

  char* Layer_6::info()
  {
  	return info;
  }

void Layer_6::operation(int Convu1[a][b],int size) 
  //Assumes a N^2 X c_previous output
  //In MaxP c-prev=c 

  {   
  	  n=int(sqrt(size));
  	  int channel[n][n];
  	  m=int(n/maxP);   
  	  int output[m*m][c];
  	  int output1[m*m]; 
  	  outputs
      for (auto i=1;i<=c;i++)
      {
        channel[n][n] = Get_matrix(Convu,n,c,i);
        j=0;
        while(auto j<n)
        	{   max=-1000;
        		output_m=0;
        		for (auto x=j;x<maxP_size;x++)
        		{
        			for (auto y=j;y<maxP;y++)
        			{
                      if(channel[x][y]>max)
                      {
                      	max=channel[x][y];
                      }
        			}
        		}
        		output1[output_m]=max;
        		output_m++;

        		j+=maxP_stride;

        	}

        	for(auto q=0;q<output_m;q++) 
        	{
              output[q][i]=output1[q];
        	}       
           


      }

    


  }

void Layer_6::show()
{
  c_show=[2,4,8,12,16,18]; // Arbitrary chossing arrays to show
  m=int(n/maxP);
  int out_show[m*m][6];
  for (auto i=0;i<m*m;i++) 
  {
  	for (auto j=0;j<6;j++)
  	{
  		out_show[i][j]=output[i][j];
  	}
  }  

  master_display(out_show); //Calling Sagar's function



}
//Something is the number of fully connected nodes.
class Layer_9
{  
private:
    int c;
    int weights[][]; //Size of fully connected weights (Something X 10 )
    int layer_flag;
    char info[500];
    int something;
    int output1[]; //Size is something
    int output2[10]; //c
    

    public:
    void load_weights();
    void operation1(int []][]); //Convert Convultion to fully connected
    void operation2(); //Multiple it by weights and produce a 10X1 Vector

};

Layer_9::Layer_9()
{
	c=10;
	// something=;
	info=""
	layer_flag=9;
	for(auto i=0;i<10;i++)
	{
		output2[i]=0;
	}
}   

void Layer_9::load_weights()
{
  
 // weights= Calls Krishna's Function

}


void Layer_9::operation1(int X[a][b],int size)   //A N^2XC matrix
{ 
 n=int(sqrt(size))*10;
 auto k=0;
 for(auto j=0;j<10;j++)
 {
 for (auto i=0;i<n/10;i++)
 { 
   output1[k]=X[i][j];
   k++;
 }
}
}

void Layer_9::operation2()
{
  for (auto i=0;i<something;i++)
  {
  	for (auto j=0;j<10;j++)
  	{
      output2[j]+=weights[j][i]*output1[i];
  	}
  }
}