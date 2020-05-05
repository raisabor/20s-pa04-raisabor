#include "Search.h"

Search::Search()
{
	

	
	
	

}

Search::~Search()
{


}

void Search::Load(string loade)
{

    TourManager::clear();
	string line;
	fstream americaOnline(loade);
    
    
    float identification, x, y, z;
    
        
    int counter = 0;


      if(americaOnline.is_open()){
       
          vector<float> tmp;
		  while (getline(americaOnline, line)) {
          
			 
			  istringstream start(line);
			  string token;
              string token2;
 
			  getline(start, token);
              
              istringstream end(token);
              
              
              while(getline(end, token2, ','))
              {
                 float temp = stof(token2);
                  
                  if(counter == 0)
                  {
                  identification = temp;
                  tmp.push_back(identification);
                  counter++;
                  continue;
              
                  }
                  
                  
                  if(counter == 1)
                  {
                  x = temp;
                  tmp.push_back(x);
                  counter++;
                  continue;
                  }
                  
                  
                  if(counter == 2)
                  {
                  y = temp;
                  tmp.push_back(y);
                  counter++;
                  continue;
                  }
                 
                  
                  if(counter == 3)
                  {
                  z = temp;
                  tmp.push_back(z);
                  
                  }
                  
              }
              vec1.push_back(Town(tmp));
              
              TourManager::addTown(Town(tmp));
              
              tmp.clear();
             
            }

          for(int f = 0; f < 7; f++)
          {
              for(int g = 0; g < 7; g++)
              {
                  ajay.insertFor(*(new Town(vec1[f])), *(new Town(vec1[g])));
              }
          }




      }
    
}
          
 

void Search::Display()
{

    if(selection[0])
    {

        cout << "Algorithm name: Naive Search"  << endl;
        cout << "Optimal Distance: " << holder << endl;
         cout << endl;

    }

	if(selection[1])
    {
	    cout << "Algorithm name: Genetic Search" << endl;


    cout << "Initial distance: " << holder1 << endl;

    cout << "Final distance: " << holder2 << endl;

    cout << "Optimal Path: " << endl;
    solution.print();

    cout << endl;
    }


    

}


void Search::Select(int level)
{
     switch(level)
     {
    case Brute:
		 selection[0] = true;
		 selection[1] = false;
         break;
     case Gene:
		 selection[1] = true;
		 selection[0] = false;
         break;
     default:
         cout << "Invalid Selection\n";
         break;
     }

}


void Search::Execute()
{

    if(selection[0])
        holder = salesMan.shortestCycle(ajay);

	if (selection[1])
	{

        //initialize population
        Population pop(50, true);
        

        holder1 = pop.getFittest().getDistance();
        // Evolve population for 100 generations
        
        for (int i = 0; i < 100; i++)
             pop = Genetic::run(pop);

        // contain final results

        holder2 = pop.getFittest().getDistance();

        solution = pop.getFittest();

	}




}
