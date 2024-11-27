#include<iostream>
#include "unordered_map"
#include "vector"
#include<map>
using namespace std;

//int maxNumber, minNumber, secretNumber,maxtry, score, 
//bool guessed
//string playerName , unordered_map 
//vctor dynamic message

enum class DynamicMessage
{
	SuccessNear,
	ThinkMore,
	SoClose,
	DontGiveUp
};

class Game
{
private:
	int maxNumber;
	int minNumber;
	int secretNumber;
	int maxTry;
	int score;

	bool Isguessed;
	
	string playerName;
	unordered_map<string, int> playerStats;
	map<DynamicMessage, string> dynamicMessageMap;

public:
	Game();

	void GenerateSecretNumber();
	void ShowHint();
	bool isPrimeNumber(int number);
	void ShowDynamicMessage();
	void SetDifficulty();
	void ResetGame();
	void StartGame();
	void DisplayStats();
	void CalculateScore(int i);


	//get-set Methods

	int getMaxNumber()const;
	void setMaxNumber(int _maxNum);

	int getMinNumber()const;
	void setMinNumber(int _minNum);

	int getSecretNumber() const;
	void setSecretNumber(int _secretNumber);

	int getMaxTry()const;
	void setMaxTry(int _tryNumber);

	int getScore() const;
	void setScore(int _score);

	bool getGuessed() const;
	void setIsGuessed(bool guess);

	string getplayerName() const;
	void setPlayerName(string _playerName);

	const unordered_map<std::string, int>& getPlayerStats() const;





	
};