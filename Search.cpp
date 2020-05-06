#include "Search.h"
#define V 12

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

          for(int j = 0; j < V; j++)
          {
              for(int k = 0; k < V; k++)
              {
                  ajay.insertFor(Town(vec1[j]),Town(vec1[k]));
              }
          }

      }
    
}
          
 

void Search::Display()
{

    if(selection[0]) {

        cout << "Algorithm name: Naive Search" << endl;
        cout << "Optimal Distance: " << holder << endl;
        cout << "Time: "<< timing << 's' << endl;
        cout << endl;

    }else{

        cout << "Algorithm name: Genetic Search" << endl;
        cout << "Initial distance: " << holder1 << endl;
        cout << "Final distance: " << holder2 << endl;
        cout << "Time: "<< timing << 's' << endl;
        cout << "Optimal Path: " << endl;

        solution.print();

        cout << endl;
    }


    

}

void Search::Save(string filename)
{

    if(!out.is_open())
        out.open(filename);

    if(out.is_open())
    {
        if(selection[0])
        {

            out << "Algorithm name: Naive Search"  << endl;
            out << "Optimal Distance: " << holder << endl;
            out << "Time: "<< timing << 's' << endl;

            out << endl;

        }else {

            out << "Algorithm name: Genetic Search" << endl;
            out << "Initial distance: " << holder1 << endl;
            out << "Final distance: " << holder2 << endl;
            out << "Time: "<< timing << 's' << endl;
            out << "Optimal Path: " << endl;

            solution.printF(out);

            out << endl;
        }
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


    if(selection[0]){
        auto start = std::chrono::system_clock::now();

        holder = salesMan.shortestCycle(ajay);

        auto end = std::chrono::system_clock::now();
        auto elapsed =  std::chrono::duration_cast<std::chrono::seconds>(end - start);
        timing = elapsed.count();

    }else{

        //initialize population
        Population pop(50, true);
        

        holder1 = pop.getFittest().getDistance();
        // Evolve population for 100 generations

        auto start = std::chrono::system_clock::now();
        for (int i = 0; i < 100; i++)
             pop = Genetic::run(pop);

        auto end = std::chrono::system_clock::now();
        auto elapsed =  std::chrono::duration_cast<std::chrono::seconds>(end - start);
        timing = elapsed.count();

        // contain final results

        holder2 = pop.getFittest().getDistance();

        solution = pop.getFittest();

	}




}
