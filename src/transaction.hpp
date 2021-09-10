#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

class Transaction {
    private:
        std::string senderAddress;
        std::string recieverAddress;

        double transactionAmount;

        u_int16_t transactionID;

    public:
        Transaction(std::string senderAddress, std::string recieverAddress, double transactionAmount, uint16_t transactionID);
        
        void printTransaction();

        friend std::ostream &operator<< (std::ostream &o_stream, Transaction transaction);

};



Transaction::Transaction(std::string senderAddress, std::string recieverAddress, double transactionAmount, u_int16_t transactionID){
    this -> transactionID = transactionID;
    this -> senderAddress = senderAddress;
    this -> recieverAddress = recieverAddress;

    if (transactionAmount >= 0){
        this -> transactionAmount = transactionAmount;
    } else {
        throw std::invalid_argument("Transaction amount can not be negative. ");
    }
}


void Transaction::printTransaction(){
    std::cout << "\nTransaction ID:       " << transactionID << std::endl;
    std::cout << "\n  Sender Address:       " << senderAddress << std::endl;
    std::cout << "  Reciever Address:     " << recieverAddress << std::endl;
    std::cout << "  Transaction Amount:   " << transactionAmount << std::endl << std::endl;
}

std::ostream &operator << (std::ostream &o_stream, Transaction transaction){
    o_stream << transaction.transactionID << transaction.senderAddress << transaction.recieverAddress << transaction.transactionAmount;

    return o_stream;
};







#endif