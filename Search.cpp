#include "Search.h"

Search::Search()
{
	

    timeSpan = 0.0;
    holder2 = 0.0;
	
	
	

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

          for(int f = 0; f < 9; f++)
          {
              for(int g = 0; g < 9; g++)
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
    //cout << "Algorithm name: " << endl;
    //cout << "Exectuion time(seconds): "<< endl;
    //cout << "Optimal Path: ";
    
    cout << endl;
    }

    if(selection[1])
    {

        cout << "Algorithm name: " << get<0>(naively) << endl;
        cout << "Exectuion time(seconds): " << get<1>(naively) << endl;
        cout << "Optimal Path: ";
        for(const int &i: holder)
        {
            cout << i << "-> ";
        }
        cout << endl;
    }
    

}
    

void Search::Stats()
{

    if(selection[1])
    {

        naively = make_pair("Naive Technique",timeSpan);

    }else{
        evolutionary = make_pair("Genetic Technique", timeSpan);
    }
  
}

void Search::Select(int level)
{
     switch(level)
     {
    case Gene:
		 selection[0] = true;
         break;
     case Brute:
		 selection[1] = true;
         break;
     default:
         cout << "Invalid Selection\n";
         break;
     }

}

void Search::Save(string path)
{
    ofstream solution;

      solution.open("path");

      if(solution.is_open())
      {
      if(selection[0])
      {
          solution << "Algorithm name: " << endl;
          solution << "Exectuion time(microseconds): " << endl;
          cout << "Optimal Path: ";
              

          solution << endl;

      }
    
    if(selection[1])
    {
    
            cout << "Algorithm name: " << endl;
            cout << "Exectuion time(microseconds): " << endl;
            cout << "Optimal Path: ";
           
            solution << endl;
        }
    }
}

void Search::Execute()
{


	if (selection[0])
	{
		chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
        
        cout << "Genetic Search" << endl;
        //initialize population
        Population pop(50, true);
        
        cout << "Initial distance: " << pop.getFittest().getDistance() << endl;
        
        // Evolve population for 100 generations
        
        for (int i = 0; i < 100; i++)
        {
        pop = Genetic::run(pop);
        }
        
        // Print final results
        cout << "Finished" << endl;
        cout << "Final distance: " << pop.getFittest().getDistance() << endl;
        cout << "Solution: " << endl;
        pop.getFittest().print();

        //pop.tours.clear();
        //delete pop;
        
		chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
		timeSpan = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
	}

    if (selection[1])
    {
        chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
        holder = salesMan.shortestCycle(ajay, 0);
        chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
        timeSpan = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    }



}
