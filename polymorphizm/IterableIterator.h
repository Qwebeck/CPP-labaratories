#include <utility>

//
// Created by falcon on 4/28/19.
//

#ifndef POLYMORPHIZM_ITERABLEITERATOR_H
#define POLYMORPHIZM_ITERABLEITERATOR_H

#include <utility>
#include <vector>
#include <string>
#include <memory>


using::std::pair;
using::std::string;

class IterableIterator {
public:
    virtual pair<int,string> Dereference() const = 0;
    virtual IterableIterator &Next() = 0;
    virtual bool NotEquals(const IterableIterator &other) = 0;
    virtual int GetIt() const = 0;
    ~IterableIterator() = default;
};

class ZipperIterator:public IterableIterator
        {
private:
            std::vector<int>::const_iterator _current_left;
            std::vector<int>::const_iterator _left_end;
            std::vector<string>::const_iterator  _current_right;
            std::vector<string>::const_iterator _right_end;
            int _it;

public:

    explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                            std::vector<std::string>::const_iterator right_begin,
                            std::vector<int>::const_iterator left_end,
                            std::vector<std::string>::const_iterator right_end,
                            int it = 0 )
                            {
                               _current_left = left_begin ;
                               _left_end = left_end;
                                _current_right = right_begin;
                               _right_end = right_end;
                               _it = it;

    };


    pair<int ,string> Dereference() const override {

        pair<int,string> dereference = std::make_pair(*_current_left,*_current_right);
        return dereference;
    }
    IterableIterator &Next() override{
        if (_current_left != _left_end)++_current_left;
        if(_current_right != _right_end)++_current_right;
        ++_it;
        return *this;
    }

    int GetIt() const override{return _it;}
    bool NotEquals(const IterableIterator &other) override
    {
        if( this -> _it != other.GetIt())
        return true;
        else return false;
    }

        };

class IterableIteratorWrapper
        {
private:
    std::unique_ptr<IterableIterator> _iterator;
public:
    explicit IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator)
    {
        _iterator = std::move(iterator);
    };
    bool operator!=(const IterableIteratorWrapper &other) const
    {
        return _iterator -> NotEquals(*other._iterator);
    }
    std::pair<int, std::string> operator*() const
            {
                return _iterator->Dereference();
            }
    IterableIteratorWrapper &operator++() const
    {
        _iterator->Next();
    }
        };

class Iterable
        {
public:
            virtual std::unique_ptr<IterableIterator> ConstBegin() const = 0;
            virtual std::unique_ptr<IterableIterator> ConstEnd() const = 0;
            IterableIteratorWrapper cbegin() const{
                return IterableIteratorWrapper(std::move(ConstBegin()));
            }
            IterableIteratorWrapper cend() const{
                return IterableIteratorWrapper(std::move(ConstEnd()));
            }
            IterableIteratorWrapper begin() const{
                return cbegin();
            };
            IterableIteratorWrapper end() const{
                return cend();
            };

        };



class Zipper:public Iterable {
private:
  std::vector<int> _left;
  std::vector<string> _right;
  ZipperIterator _iterator;
//  IterableIteratorWrapper _wrapper;

public:
    Zipper(std::vector<int> left,std::vector<string> right):_iterator(left.begin(),right.begin(),left.end(),right.end())
    //,_wrapper(std::make_unique<IterableIterator>(left.begin(),right.begin(),left.end(),right.end()))
    {
        _left = left;
        _right = right;
    };
    std::unique_ptr<IterableIterator> ConstBegin() const override {
        return std::make_unique<ZipperIterator>(_left.begin(),_right.begin(),_left.end(),_right.end());
    }
    std::unique_ptr<IterableIterator> ConstEnd() const override {
        return std::make_unique<ZipperIterator>(--_left.end(),--_right.end(),_left.end(),_right.end() , 3);
    }
};


#endif //POLYMORPHIZM_ITERABLEITERATOR_H
