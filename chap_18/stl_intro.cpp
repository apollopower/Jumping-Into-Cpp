// Intro to the Standard Template Library:

# include <iostream>

# include <vector> // we need to include vector from the STL
# include <map>    // just like vectors, need to include from STL

using namespace std; // <- Required for STL use



// Function protype for use when covering iterators and maps
void displayMap(map<string, string> map_to_print);

int main() 
{
    // VECTORS:
    
    // Creating a new vector
    vector<int> a_vector(10); // creates a vector with size 10

    // It works just like a normal array:
    for (int i = 0; i < 10; i++) {
        a_vector[i] = i + 1;
        cout << a_vector[i] << endl;
    }

    // But its also dynamic, and can take new inputs:
    a_vector.push_back(11); // inserts 11 as a new element at end of vector

    // Notice the notation (looks like higher lvl languages):

    // object.function_call(argument)

    // We can also do things like check size:
    cout << a_vector.size() << endl; // should now be size 11!


    // MAPS:

    // Maps are essentially Ruby hashes, JS Objects,
    // and Python dictionaries
    map<string, string> name_to_email; // Notice the format

    // -With STL syntax, we use the <> for the data structure
    // -We provide the data type for the key & value, respectively
    // -Declare Map name! This case, name_to_email

    // To add a value to a map, we insert the key type specified and
    // define a value for the key-value pair
    name_to_email["Jonas Erthal"] = "jonas@pollock.ai";

    // Then to get the value, just call the map and its key:
    cout << name_to_email["Jonas Erthal"] << endl;

    // Its easy to remove items from a map as well:
    name_to_email.erase("Jonas Erthal"); // provide the key as the arg

    // We can also check the size:
    name_to_email.size();

    // And we can check if a map is empty:
    if (name_to_email.empty()) { // returns a boolean
        cout << "You have an empty address book!\n";
    }

    // This is not to be confused with how we make maps empty,
    // which we would do:
    name_to_email.clear(); // deletes all entries in map

    // STL containers use a consistent naming convention, so we 
    // use clear and empty as well on on vectors.


    // ITERATORS

    // An iterator is a variable that allows us to sequentially
    // access each element of any given data structure, even if
    // the data structure normally doesn't provide a way of doing
    // this.

    // Declaring an iterator requires some unusual syntax:
    //  vector<int>::iterator;

    // This syntax basically says that you have a vector<int>, and
    // you want to have an iterator that works for this type.

    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // the mumbo-jumbo in the beginning almost looks like
    // you are delcaring a data type:
    vector<int>::iterator itr = vec.begin();

    // The call to begin returns an iterator that lets you
    // access the first element of the vector

    // You can think of an iterator being similiar to a
    // pointer, using similiar syntax. It lets you talk about
    // the location of an element in a data structure.
    // In this case, we can read the first element of our
    // vector with the following syntax:

    cout << *itr << endl; // prints out the first element in the vector above

    // To get the next element of the vector, we can increment
    // the iterator:
    itr++;

    // We can also use the prefix operator:
    ++itr; // This is more efficient because it returns the value
           // of the expression after doing the increment

    // We can check to see if we're at the end of an iterator
    // by comparing current iterator to the end iterator:
    vec.end();

    // So to loop over an entire vector, we would write:
    vector<int>::iterator end = vec.end();
    for (vector<int>::iterator itr = vec.begin();
        itr != end;
        ++itr) // just like a normal for loop!
    {
        cout << *itr << endl;
    }

    // FUN FACT:
    // We can add multiple variables into the first part of
    // the for loop, so we can make the above code a little
    // nicer:
    for(vector<int>::iterator itr = vec.begin(),
        end = vec.end(); // still first part of for loop definition!
        itr != end; ++itr)
    {
        cout << *itr << endl;
    }

    // We can also use iterators with maps!

    // For maps, iterators have two fields (accessed just like
    // pointers!). These are first, and second:

    // int key = itr->first; // provides key
    // int value = itr->second; // provides value

    // Here's an example of using an iterator over a map:
    // refer to displayMap function below main()

    name_to_email["Jonas Erthal"] = "jonas@pollock.ai";

    displayMap(name_to_email);

    // Great!

    // We can also check if a key is already stored in 
    // a map, we can use the find() method, which returns
    // an iterator:

    map<string, string>::iterator iter = name_to_email.find("Jonas Erthal");
    if (iter == name_to_email.begin()) {
        cout << "How nice to see Jonas in the book! His email is: "
             << iter->second << endl;
    }

}

void displayMap(map<string, string> map_to_print) {
    for(map<string, string>::iterator itr = map_to_print.begin(),
        end = map_to_print.end();
        itr != end; ++itr)
    {
        cout << itr->first << " => " << itr->second << endl;
    }
}