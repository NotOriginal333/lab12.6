#include <iostream>
#include <fstream>
#include <string>
#include <queue>

std::queue<std::string> createQueueFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::queue<std::string> wordQueue;
    std::string word;

    while (file >> word) {
        wordQueue.push(word);
    }

    return wordQueue;
}

void printQueue(const std::queue<std::string>& wordQueue) {
    std::cout << "Elements of the queue:" << std::endl;
    std::queue<std::string> tempQueue = wordQueue; 
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << std::endl;
        tempQueue.pop();
    }
}

int countQueueElements(const std::queue<std::string>& wordQueue) {
    return wordQueue.size();
}

void printWordsOfLength(const std::queue<std::string>& wordQueue, int length) {
    std::cout << "Words of length " << length << ":" << std::endl;
    std::queue<std::string> tempQueue = wordQueue; 
    while (!tempQueue.empty()) {
        std::string word = tempQueue.front();
        if (word.length() == length) {
            std::cout << word << std::endl;
        }
        tempQueue.pop();
    }
}

void destroyQueue(std::queue<std::string>& wordQueue) {
    while (!wordQueue.empty()) {
        wordQueue.pop();
    }
}

int main() {
    std::string filename = "words.txt"; 
    std::queue<std::string> wordQueue = createQueueFromFile(filename);

    printQueue(wordQueue);

    int wordLength;
    std::cout << "Enter the length of words to search for: ";
    std::cin >> wordLength;
    printWordsOfLength(wordQueue, wordLength);

    destroyQueue(wordQueue);

    return 0;
}
