#include "Game.h"
#include <ctime>
#include <chrono>
#include <cstdlib>



Game::Game()
{
	minNumber = 1;
	maxNumber = 100;
	maxTry = 5;
	Isguessed = false;

	 dynamicMessageMap = {
	 {DynamicMessage::SuccessNear, "Success is near!"},
	 {DynamicMessage::ThinkMore, "Think a little more!"},
	 {DynamicMessage::SoClose, "Come on, you're so close to the right guess!"},
	 {DynamicMessage::DontGiveUp, "Don't give up, keep trying!"}
	};


}

void Game::GenerateSecretNumber()
{
	srand(time(0));
	secretNumber = rand() % (maxNumber - minNumber + 1) + minNumber;
}

void Game::ShowHint()
{
	cout << "***HINT***" << endl;

	if (secretNumber % 2 == 0)
	{
		cout << "Number is even !!!" << endl;
	}
	else
	{
		cout << "Number is odd !!!" << endl;
	}
	if (isPrimeNumber(secretNumber))
	{
		cout << "Number is prime !!!" << endl;
	}
	else
	{
		cout << "Number is not prime!!!" << endl;
	}


}

bool Game::isPrimeNumber(int number)
{
	if(number<=1)
	return false;

	for (int i = 2; i * i <= number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

void Game::ShowDynamicMessage()
{
	
	int randomIndex = rand() % dynamicMessageMap.size();
	auto it = dynamicMessageMap.begin();
	std::advance(it, randomIndex);

	std::cout << it->second << std::endl;
}

void Game::SetDifficulty()
{
	int difficulty;
	cout << "Select the difficulty level(1: Easy, 2 : Medium, 3 : Hard) :" << endl;
	cin >> difficulty;

	switch (difficulty)
	{
	case 1:
		minNumber = 1;
		maxNumber = 50;
		maxTry = 5;
		break;

	case 2:
		minNumber = 1;
		maxNumber = 100;
		maxTry = 5;
		break;

	case 3:
		minNumber = 1;
		maxNumber = 200;
		maxTry = 3;
		break;
		
	default:
		cout << "Invalid selection! Medium difficulty selected by default " << endl;
		
	}

}



void Game::StartGame()
{
	cout << "*** Welcome ***" << endl;
	cout << "Enter the name : ";
	cin >> playerName;
	SetDifficulty();

	while (true)
	{
		GenerateSecretNumber();
		Isguessed = false;

		auto startTime = chrono::high_resolution_clock::now();

		std::cout << "Enter the number between : " << minNumber << " and  " << maxNumber << std::endl;

		for (int i = 1; i <= maxTry; i++)
		{
			int guessNumber;
			cin >> guessNumber;

			if (guessNumber == secretNumber)
			{
				cout << "Congratulations, you guessed right! " << endl;
				Isguessed = true;
				CalculateScore(i);
				playerStats["Wins"]++;
				break;
			}
			else if (guessNumber < secretNumber)
			{
				cout << "Your number is small! Try a larger number " << endl;
				Isguessed = false;
			}
			else
			{
				cout << "Your number is big! Try a smaller number" << endl;
				Isguessed = false;
			}
			
			if (i == 3)
			{
				ShowHint();
				ShowDynamicMessage();

			}
		}
		auto endTime = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = endTime - startTime;

		int minutes = chrono::duration_cast<std::chrono::minutes>(elapsed).count();
		int seconds = chrono::duration_cast<std::chrono::seconds>(elapsed).count() % 60;

		if (!Isguessed)
		{
			std::cout << "You've lost! That's the right number:  " << secretNumber << std::endl;
			playerStats["Losses"]++;

		}

		cout << "Time: " << minutes << " minutes  " << seconds << " seconds " << endl;

		char playAgain;

		cout << " Try again (y/n) : ";
	    cin >> playAgain;

		if (playAgain == 'y' || playAgain == 'Y')
		{
			ResetGame();
			DisplayStats();
			continue;

		}
		DisplayStats();
		break;
		
	
	}



}

void Game::DisplayStats()
{
	cout << "Player: " << playerName << endl;
	cout << "Win Games: " << playerStats["Wins"] <<endl;
	cout << "Lose Games: " << playerStats["Losses"] << endl;
	cout << "Total scor: " << score << endl;
}

void Game::CalculateScore(int i)
{
	score+= (maxTry - i + 1) * 10;

}

void Game::ResetGame()
{
	Isguessed = false;
}


// Getter Setter

int Game::getMaxNumber() const
{
	return maxNumber;
}

void Game::setMaxNumber(int _maxNum)
{
	maxNumber = _maxNum;
}

int Game::getMinNumber() const
{
	return minNumber;
}

void Game::setMinNumber(int _minNum)
{
	minNumber = _minNum;
}

int Game::getSecretNumber() const
{
	return secretNumber;
}

void Game::setSecretNumber(int _secretNumber)
{
	secretNumber = _secretNumber;
}

int Game::getMaxTry() const
{
	return maxTry;
}

void Game::setMaxTry(int _tryNumber)
{
	maxTry = _tryNumber;
}

int Game::getScore() const
{
	return score;
}

void Game::setScore(int _score)
{
	score = _score;
}

bool Game::getGuessed() const
{
	return Isguessed;
}

void Game::setIsGuessed(bool guess)
{
	Isguessed = guess;
}

string Game::getplayerName() const
{
	return playerName;
}

void Game::setPlayerName(string _playerName)
{
	playerName = _playerName;
}

const unordered_map<std::string, int>& Game::getPlayerStats() const 
{ 
	return playerStats; 
}

