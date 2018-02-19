#include <stdlib.h>
template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
	     s=0;
	     v=NULL;
      }
      ~vector(){
	     delete [] v;
      }
      int size() {
	     return s;
      }
      void push_back(T ele) {
	     T *temp;
	     temp = new T[s];
	     for(int i=0; i<s-1; i++)
			 temp[i]=v[i];

		 delete [] v; 
		 s++;
		 v = new T[s];
		 
		 for(int i=0; i<s-1; i++)
			 v[i]=temp[i];
		 
		 v[s-1]=ele;
		 delete [] temp;
      }
	  vector(vector<T> &other){
		  s = other.len;
		  if(s == 0){
			  v = NULL;
		  }
		  else{
			  v = new vector<T>[s];
			  for(int i = 0; i < s; i++){
				  v[i] = other.at(i);
			  }
		  }
	  }
	  void operator= (vector<T> &other){
		  if(s != NULL){
			  delete [] v;
		  }
		  s = other.len;
		  if(s == 0){
			  v = NULL;
		  }
		  else{
			  v = new vector<T>[s];
			  for(int i = 0; i < s; i++){
				  v[i] = other.at(i);
			  }
		  }
	  }
	  T operator[] (int){
		  
	  }
	  void resize(){
		  
	  }
	  T at(int){
		  
	  }
};