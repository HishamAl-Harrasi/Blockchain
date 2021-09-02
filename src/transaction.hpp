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

std::ostream &operator << (std::ostream &o_stream, Transaction transaction){
    o_stream << "\nTransaction ID:       " << transaction.transactionID << std::endl;
    o_stream << "\n  Sender Address:       " << transaction.senderAddress << std::endl;
    o_stream << "  Reciever Address:     " << transaction.recieverAddress << std::endl;
    o_stream << "  Transaction Amount:   " << transaction.transactionAmount << std::endl << std::endl;

    return o_stream;
};






#endif