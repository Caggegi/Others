/*
    Made by Rosario Caggegi
    Scope: Show the Monty Hall paradox and how it works
*/

#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

int simulation();
void tutorial();
int play();
int perdente(int scelta, int vincente);

int main(int argc, char* argv[]){
  int chose=1;
  do{
    cout<<"\nVuoi giocare o vuoi vedere la simulazione di gioco?"<<endl;
    cout<<"1.Voglio giocare\n2.Voglio vedere la simulazione\n3.Spiegazione del gioco\n0.Esci dall'applicazione\nScegli: ";
    cin>>chose;
    switch(chose){
      case 1:
        if(play()){
          cout<<"si e' verificato un errore sconosciuto, impossibile eseguire la simulazione.\nUscita in corso...";
          chose=0;
        }
        break;
      case 2:
        if(simulation()){
          cout<<"si e' verificato un errore sconosciuto, esco dall'applicazione\nUscita in corso...";
          chose=0;
        }
        break;
      case 3:
        tutorial();
        break;
      }
  } while(chose);

  return 0;
}

int simulation(){
  int n=0, w=0;
  int c=3;
  srand(time(NULL));
  cout<<"\n\tQuante volte vuoi far girare la simulazione? ";
  cin>>n;
  do{
    cout<<"\n\n\tCosa vuoi simulare?\n\t1.Cambia sempre;\n\t2.Mantieni sempre la risposta\n\t3.Sia l'uno che l'altro random\n\tScelta: ";
    cin>>c;
  } while(c<1 || c>3);
  switch(c){
  	case 1:
  	  for(int i=0; i<n; i++){
       	int car=rand()%3;
       	int porta=rand()%3;
       	if(porta!=car)
       	  w++;
      }
   	  break;
  	case 2:
      for(int i=0; i<n; i++){
        int car=rand()%3;
        int porta=rand()%3;
        if(porta==car)
          w++;
      }
  	  break;
  	case 3:
      for(int i=0; i<n; i++){
        int car=rand()%3;
        int porta=rand()%3;
        int cambio=rand()%2;
        if(porta==car){
          if(cambio){
            w++;
          }
        } else{
          if(!cambio){
            w++;
          }
        }
      }
      break;
  }
  float vittorie = w;
  cout<<"\n\n\tIl computer ha vinto il "<<vittorie/n*100<<"% delle volte con "<<n<<" simulazioni\n\n\n\n\n\n";
  return 0;
}

void tutorial(){
  cout<<"\n\n\tIl gioco consiste nel scegliere la porta vincente tra 3 porte.\n";
  cout<<"\tCi sono 3 porte, dietro due di queste ci sono capre, dietro quella vincente invece un'automobile\n";
  cout<<"\tIl giocatore sceglie una porta. Il computer apre una delle due restanti\n\tdove sicuramente c'e' una capra e dice:\n";
  cout<<"\t\"Vuoi cambiare la tua scelta?\"\n";
  cout<<"\tSi verificano cosi' quattro situazioni: \n\til giocatore cambia la porta ma quella che aveva scelto all'inizio era vincente di conseguenza perde;\n\t";
  cout<<"il giocarore cambia la porta e dato che quella che aveva scelto all'inizio era perdente vince il gioco\n\t";
  cout<<"il giocarore non cambia la porta e dato che quella che aveva scelto all'inizio era perdente, perde il gioco\n\t";
  cout<<"il giocarore non cambia la porta e dato che quella che aveva scelto all'inizio era vincente, vince il gioco\n\n\n";
}

int play(){
  srand(time(NULL));
  int car=rand()%3;
  int scelta;
  char s;
  do{
  cout<<"\n\n\t\t+-------+\t+--------+\t+--------+\n\t\t|        |\t|        |\t|        |\n\t\t|        |\t|        |\t|        |\n\t\t|   0    |\t|   1    |\t|   2    |\n\t\t|        |\t|        |\t|        |\n\t\t|        |\t|        |\t|        |\n\t\t|        |\t|        |\t|        |\n\t\t+--------+\t+--------+\t+--------+\n\n\n";
  cout<<"\tScegli una porta (scegli tra 0,1 o 2): ";
  cin>>scelta;
  } while(scelta<0 || scelta>2);
  int porta=perdente(scelta, car);
  cout<<"\tApro la porta "<<porta<<", che e' perdente, vuoi cambiare la tua scelta? (s/n)\n\t";
  cin>>s;
  if(s=='s'){
    if(scelta!=car)
      cout<<endl<<"\tHai vinto"<<endl;
    else
      cout<<endl<<"\tHai perso, la porta vincente era la porta "<<car<<endl;
  } else{
    if(scelta==car)
      cout<<endl<<"\tHai vinto"<<endl;
    else
      cout<<endl<<"\tHai perso, la porta vincente era la porta "<<car<<endl;
  }
  return 0;
}

int perdente(int scelta, int vincente){
  if(scelta==vincente){
    switch(scelta){
     case 0:
        if(rand()%2)
          return 1;
        else
          return 2;
        break;
      case 1:
        if(rand()%2)
          return 0;
        else
          return 2;
        break;
      case 2:
        if(rand()%2)
          return 0;
        else
          return 1;
        break;
    }
  }
  else{
    switch(scelta){
      case 0:
        if(vincente==1)
          return 2;
        else
          return 1;
        break;
      case 1:
        if(vincente==2)
          return 0;
        else
          return 2;
        break;
      case 2:
        if(vincente==0)
          return 1;
        else
          return 0;
        break;
    }
  }
}
