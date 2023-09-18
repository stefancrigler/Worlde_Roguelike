#include<string>
#include<map>
#include<vector>
#include<tuple>
#include<fstream>

class Wordle {
    private:
        int word_length;
        std::string word;
    public:
        std::string getWord(){
            return word;
        }
        void setWord(std::string w){
            word = w;
            word_length = w.length();
        }

        Wordle(std::string the_word){
            word = the_word;
            word_length = the_word.length();
        }
        Wordle(){
            word = "basic";
            word_length = 5;
        }
};

class char_state {
    private:
       std::map<char, int> key_list;
    public:
        void set_key(char c, int state){
            key_list[c] = state;
        }
        int get_key_state(char c){
            return key_list[c];
        }
        // char_state(std::vector<char,int> initial_state){
        //     std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
        //     for(int i=0; i < 26; i ++){
        //         key_list[alphabet[i]] = 0;
        //     }
        //     //TODO: utilize the initial state
        //     // for(unsigned int i = 0; i < initial_state.size(); i++)
        //     // {
        //     //     // key_list[initial_state[i]] = initial_state[i][1];
        //     // }
        // }
        char_state(){
            std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
            for(int i=0; i < 26; i ++){
                key_list[alphabet[i]] = 0;
            }
        }

};

class GameInstance {
    private: 
        char_state key_state;
        Wordle word;
        int guesses;
    public:
        std::string get_word(){
            return word.getWord();
        }
        char_state get_key_state(){
            return key_state;
        }
        void set_key_state(char c, int state){
            key_state.set_key(c, state);
        }
        void begin_round(){
            while(guesses){
                std::string user_guess;
                cout<<"make a guess!"<<endl;
                cin>>user_guess;
                if(user_guess.length() != word.getWord().length()){
                    cout<<"guess was incorrect length"<<endl;
                    continue;
                }
                for(int i = 0; i < word.getWord().length(); i ++){
                    if(user_guess[i] == word.getWord()[i]){ //green match
                        key_state.set_key(user_guess[i], 2); //TODO user a declared value here
                    }
                }
            }
        }
        GameInstance(){
            std::fstream word_list;
            word_list.open("Words.txt");
            if (word_list.is_open()){ //checking whether the file is open
                std::string tp;
                while(getline(word_list, tp)){ //read data from file object and put it into string.
                    word.setWord(tp);
                    break;
                }
                word_list.close(); //close the file object.
            }
            guesses = 5;
        }

};