#include <iostream>
using namespace std;

#define N 3

class TicTacToe{
	public:
		TicTacToe();
		bool ifBoxISEmpty(int x, int y, char mark);
		char ifIsWinner();
		void nextPlayer();
		void print();
		bool checkMark(char mark);
		bool corInput(int x, int y);
		int getPlayer();
	private:
		char board[N][N];
		int player;	
};


int main(){
	
	// Arxikopoiisi antikeimenou.
	TicTacToe t;
	
	int x,y,moves = 0;
	char mark;
	char board[N][N];
	
	
	while(true){
	    
	    t.print();
    	cout << endl << endl;
    	
    	// Epilogi simvolou apo ton paikti.
    	cout << "player  " << t.getPlayer() << "  me ti simvolo thes na paikseis? Apanta me 'O','o','X','x': ";
    	cin >> mark;
    	
    	cout << endl << endl;
    	
    	// Tsekaroume an i eisodos einai swsti an einai true proxwraei parakatw an einai false paei pali apo tin arxi.
    	if(!t.checkMark(mark)){
    	    cout << "Lathos kinisi!!";
    	    continue;
    	}
    	
    	cout << endl << endl;
    	cout << "player  " << t.getPlayer() << " to simvolo sas einai :" << mark << endl;
    	cout << endl << endl;
    	
    	// Eisodos sintetagmenwn apo ton paikti. 
    	cout << "Se poia thesi thes na paikseis to simvolo " << mark << "? Apanta me arithmo grammis arithmo stilis, apo 0 mexri 2, XWRIS KOMMA(p.x. 0 0):" << endl;
    	cin >> x >> y;
    	
    	// Tsekaroume an i eisodos sintetagmenwn einai swsti an einai true proxwraei parakatw an einai false paei pali apo tin arxi.
    	if(!t.corInput(x,y)){
    	    cout << "Valte swstes sintetagmenes!!" << endl;
    	    continue;
    	}
    	
    	// Elegxos thesis pinaka an einai true paei parakatw an einai false paei apo tin arxi.
    	if(!t.ifBoxISEmpty(x,y,mark)){
    	    cout << "Lathos kinisi!!" << endl;
    	    continue;
    	}
    	else
    	    moves++;
    	
    	// Elegxos euresis nikiti h isopalias. 
    	if(t.ifIsWinner() != '-'){
    	    t.print();
    	    cout << "Nikise o  " << t.getPlayer() << "  !!!" << endl;
    	    break;
    	}
    	else if(moves == 9){
    	    t.print();
    	    cout << "Isopalia!!" << endl;
    	    break;
    	}
	    
	    // Enalagi paikti
	    t.nextPlayer(); 
	}
	
	
	system("PAUSE");
	return 0;
}


TicTacToe::TicTacToe(){
	
	for(int i=0; i<N; i++)
    	for(int j=0; j<N; j++)   		
    		board[i][j] = '-';
    
    player = 1;
}



void TicTacToe::print(){
	
	
	cout << endl << endl;
	cout << "TRILIZA\n" << endl;
	cout << "-----------------------------------------\n" << endl << endl;
	cout << "\t      " << "|" <<"     " << "|"<< endl;
    cout << "\t   " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "\t -----+-----+-----" << endl;
    cout << "\t   " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "\t -----+-----+-----" << endl;
    cout << "\t   " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
	cout << "\t      " << "|" <<"     " << "|"<< endl;    
}


int TicTacToe::getPlayer(){
    return player;
}



bool TicTacToe::checkMark(char mark){
    
    if(mark == 'O' || mark == 'o' || mark == 'X' || mark == 'x'){
    	return true;
	}
	else
		return false;
	
}

bool TicTacToe::corInput(int x, int y){
    
    if(x >= 0 && x <= 2 || y >= 0 && y <= 2){
        return true;
    }
    else
        return false;
}

void TicTacToe::nextPlayer(){
	
	if(player == 1){
		player = 2;
	}		
	else
		player = 1;
}


bool TicTacToe::ifBoxISEmpty(int x, int y, char mark){
	
	if(x >= 0 && x <= 2 || y >= 0 && y <= 2){
	    if(mark == 'O' || mark == 'o' || mark == 'X' || mark == 'x'){
	        if(board[x][y] == '-'){
	            board[x][y] = mark;
	            return true;
	        }
	        else
	            return false;
	    }
	    else
            return false;
    }
    else
        return false;
}


char TicTacToe::ifIsWinner(){
	
	// Elegxoume an iparxei nikitis stis grammes
	for(int i=0; i<N; i++){
		if(board[i][0] == board [i][1] && board[i][1] == board [i][2])
		    return board[i][0];
	}
	
	// Elegxoume an iparxei nikitis stis stiles
	for(int j=0; j<N; j++){
		if(board[0][j] == board [1][j] && board[1][j] == board [2][j])
		    return board[0][j];
	}
	
	// Elegxoume an exei nikisei me diagwnio 0,0 + 1,1 + 2,2
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
	    return board[0][0];
	    
	    
	// Elegxoume an exei nikisei me diagwnio 0,2 + 1,2 + 2,0
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
	    return board[0][2];
	    
	return '-';	
}
