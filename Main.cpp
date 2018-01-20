#include <iostream>
using namespace std;

class DNode 
{
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode()
	 {
	  data = 0; 
	  next = NULL; 
	  prev = NULL; 
	  } 
    DNode(int d=0, DNode* n = NULL, DNode* p = NULL)
	 {
	  data = d; 
	  next = n; 
	  prev = p; 
	  }
   
};

class DLL 
{
private:
    DNode* front;
public:
    DLL ()
	 {
	  front = NULL; 
	  } 

    void insert_to_front(int item)
    {
        DNode* nn = new DNode(item, front, NULL);
        if(front != NULL)
        front->prev = nn;
        front = nn;
    }
    
   void insert_to_back(int item)
    {
        if (front == NULL)
            front = new DNode(item);
        else {
            DNode* p = front;
            while (p->next != NULL)
                p = p->next;
            p->next = new DNode(item,NULL,p);

        }
    }
    
	void delete_from_front()
    {
    	if(front == NULL)
    	{
    		cout<<"list is empty"<<endl;
		}
		else if(front->next == NULL)
		{
			delete(front);
			
		}
    	else
    	{
    		DNode* p = front->next;
    		delete(front);
    		p->prev = NULL;
    		front = p;
    
		}
    	
	}
	
	
	void delete_from_back()
    {
    	if(front == NULL)
    	{
    		cout<<"list is empty"<<endl;
		}
		else if(front->next == NULL)
		{
			delete(front);
		}
    	else
    	 {
            DNode* p = front;
            while (p->next != NULL)
            {
                p = p->next;
            }
           p->prev->next = NULL;
            delete(p);
            

        }
    	
	}
	
    void print()
    {
    
         DNode* p = front;
         if(front == NULL)
         {
         	cout<<"list is empty"<<endl;
		 }
		 else
		 {
		 
        while (p != NULL)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
    }
    
   DNode* findMiddle()
	{
		int position = 1;
   		DNode* slow_ptr = front;
    	DNode* fast_ptr = front;
    	DNode* s1 = front;
    	
    	if(front == NULL)
    	{
    		cout<<"List is empty"<<endl;
    		return NULL;
		}
		
		else if(front->next == NULL)
		{
			return front;
			
		}
 
    else 
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            position++;
        }
	
        for(int i = 1; i< position; i++)
		{
           s1 = s1->next;
        }
      return s1;
	
    }
	
   	} 

	void delete_middle()
	{
		DNode* middle;
   		
    	if(front == NULL)
    	{
    		cout<<"List is empty"<<endl;
		}
		
		else if(front->next == NULL)
		{
			front = NULL;
			delete(front);
			
		}
 
    else 
    {
        middle = findMiddle();
        
        if(middle == front)
        {
        	front = NULL;
        	delete(middle);
		}
        
       else if(middle->next == NULL)
        {
        	front->next = NULL;
        	delete(middle);
        	
		}
		else
		{
		
       middle->prev->next = middle->next;
       middle->next->prev = middle->prev;
        delete(middle);
    }
	
    }
   
}

void insert_middle(int value)
    {
    	
    	DNode* temp;
	    DNode* middle;
       if(front == NULL)
       {
       	cout<<"Currently no element present in the list"<<endl;
       	temp = new DNode(value);
       	front = temp;
	   }
      else if(front->next == NULL)
       {
       	cout<<"Currently only one element present in the list"<<endl;
       	temp = new DNode(value,NULL,front);
       	front->next = temp;
	   }
 
    else
    {
    	middle  = findMiddle();
        temp = new DNode(value,middle,middle->prev);
     middle->prev->next = temp;
     middle->prev = temp;
	
    }
   
	}   
    
    DNode* findMin()
    {
        DNode* moving_ptr;
        DNode* min;
        min = front;
        moving_ptr = front;
              while(moving_ptr != NULL)
                {
                     if(moving_ptr->data < min->data)
                        {
                         min = moving_ptr;
                        }
                     moving_ptr = moving_ptr->next;
                 }
                 return min;
    }
    
     
    
    void delete_in_Ascending_order()
    {
       while(front != NULL)
          {
          	 DNode* minimum;
             minimum = findMin();
            
            if(minimum == front)

             {
                 front = front->next;
                 delete(minimum);

             }
             else if(minimum->next == NULL)
             {
             	minimum->prev->next = NULL;
             	delete(minimum);
             	
			 }
              else
			  {
              	  minimum->prev->next = minimum->next;
                  minimum->next->prev = minimum->prev;
                  delete(minimum);
                  
                 }

          }
        
          cout<< "All nodes deleted in ascending order . Now doubly linked list is empty "<< endl;
    }

};

int main(int argc, const char * argv[]) {
    
	DLL* dlist = new DLL();
    dlist->insert_to_front(2);
    dlist->insert_to_front(3);
    dlist->delete_middle();
    dlist->print();
    dlist->delete_middle();
    dlist->print();
    dlist->insert_to_front(4);
    dlist->insert_to_front(5);
     dlist->insert_to_front(6);
   dlist->insert_to_back(1);
   dlist->insert_to_back(0);
   dlist->insert_to_back(12);
   dlist->insert_to_back(7);
    dlist->print();
    dlist->delete_from_front();
    dlist->print();
    dlist->delete_from_back();
    dlist->print();
    dlist->delete_middle();
    dlist->print();
    dlist->delete_middle();
    dlist->print();
   dlist->insert_middle(8);
   dlist->print();
   dlist->insert_middle(9);
   dlist->print();
    cout<<"minimum value is : ";
    cout<<dlist->findMin()->data<<endl;
   dlist->delete_in_Ascending_order();
   dlist->print();
    return 0;
}

