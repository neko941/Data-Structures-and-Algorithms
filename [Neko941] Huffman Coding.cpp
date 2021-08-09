#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> freq;
int fill_data;
string text;
unordered_map<char, string> huffmanCode;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

Node *getNode(char ch, int freq, Node *left, Node *right)
{
    Node *node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

void encode(Node *root, string str,
            unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    // found a leaf node
    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void decode(Node *root, int &index, string str)
{
    if (root == nullptr)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

Node *build_tree()
{
    priority_queue<Node *, vector<Node *>, compare> pq;
    for (auto pair : freq)
    {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    encode(pq.top(), "", huffmanCode);
    return pq.top();
}

void print_encoded_table()
{
    printf("\nResult Table:");

    int i;
    for (i = 0; i < 41; i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 218);
        }
        else if (i == 8 || i == 24)
        {
            printf("%c", 194);
            continue;
        }
        else if (i == 40)
        {
            printf("%c", 191);
        }
        else
        {
            printf("%c", 196);
        }
    }

    printf("\n\t%cLetter\t%cCode\t\t%cFrequency\t%c", 179, 179, 179, 179);

    for (i = 0; i < 41; i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 195);
        }
        else if (i == 8 || i == 24)
        {
            printf("%c", 197);
            continue;
        }
        else if (i == 40)
        {
            printf("%c\n", 180);
        }
        else
        {
            printf("%c", 196);
        }
    }

    for (auto pair : huffmanCode)
    {
        auto it = freq.find(pair.first);
        printf("\t%c", 179);
        cout << pair.first;
        printf("\t%c", 179);
        cout << pair.second;
        if (pair.second.length() < 7)
        {
            printf("\t\t%c%d\t\t%c\n", 179, it->second, 179);
        }
        else
        {
            printf("\t%c%d\t\t%c\n", 179, it->second, 179);
        }
    }

    for (i = 0; i < 41; i++)
    {
        if (i == 0)
        {
            printf("\t%c", 192);
        }
        else if (i == 8 || i == 24)
        {
            printf("%c", 193);
            continue;
        }
        else if (i == 40)
        {
            printf("%c", 217);
        }
        else
        {
            printf("%c", 196);
        }
    }
}

void encoding_string()
{
    cout << "\n\nOriginal String: " << text << '\n';
    string str = "";
    for (char ch : text)
    {
        str += huffmanCode[ch];
    }
    cout << "\nEncoded String:\n" << str;
}

void decoding_string(Node *root)
{
    cout << "\n\nEncoded String: " << text << '\n';
    int index = -1;
    printf("\nDecoded String: ");
    while (index < (int)text.size() - 2)
    {
        decode(root, index, text);
    }
}

void initialize_data()
{
    freq[' '] = 2725;
    freq['!'] = 2;
    freq['"'] = 504;
    freq['#'] = 8;
    freq['$'] = 1;
    freq['%'] = 1;
    freq['&'] = 8;
    freq['('] = 2;
    freq['*'] = 2;
    freq['+'] = 29;
    freq[','] = 3;
    freq['-'] = 94;
    freq['.'] = 89;
    freq['/'] = 277;
    freq['0'] = 167;
    freq['1'] = 72;
    freq['2'] = 43;
    freq['3'] = 37;
    freq['4'] = 26;
    freq['5'] = 27;
    freq['6'] = 8;
    freq['7'] = 12;
    freq['8'] = 11;
    freq['9'] = 22;
    freq[':'] = 77;
    freq[';'] = 1;
    freq['<'] = 144;
    freq['='] = 254;
    freq['>'] = 144;
    freq['?'] = 11;
    freq['@'] = 9;
    freq['A'] = 45;
    freq['B'] = 10;
    freq['C'] = 11;
    freq['D'] = 7;
    freq['E'] = 14;
    freq['F'] = 7;
    freq['G'] = 1;
    freq['H'] = 1;
    freq['I'] = 25;
    freq['J'] = 1;
    freq['K'] = 9;
    freq['L'] = 4;
    freq['M'] = 7;
    freq['N'] = 3;
    freq['O'] = 6;
    freq['P'] = 36;
    freq['Q'] = 1;
    freq['R'] = 5;
    freq['S'] = 13;
    freq['T'] = 37;
    freq['U'] = 2;
    freq['V'] = 2;
    freq['W'] = 9;
    freq['Y'] = 8;
    freq['Z'] = 4;
    freq['['] = 8;
    freq[']'] = 8;
    freq['_'] = 46;
    freq['`'] = 2;
    freq['a'] = 371;
    freq['b'] = 41;
    freq['c'] = 189;
    freq['d'] = 249;
    freq['e'] = 712;
    freq['f'] = 170;
    freq['g'] = 125;
    freq['h'] = 188;
    freq['i'] = 441;
    freq['j'] = 44;
    freq['k'] = 11;
    freq['l'] = 239;
    freq['m'] = 299;
    freq['n'] = 212;
    freq['o'] = 150;
    freq['p'] = 271;
    freq['q'] = 5;
    freq['r'] = 400;
    freq['s'] = 165;
    freq['t'] = 531;
    freq['u'] = 47;
    freq['v'] = 23;
    freq['w'] = 27;
    freq['x'] = 162;
    freq['y'] = 103;
    freq['z'] = 6;
    freq['{'] = 2;
}

void implementation()
{
    initialize_data();
    while (1)
    {
        printf("%c%c%c%c%c%c%c%c%c%c   MENU   %c%c%c%c%c%c%c%c%c%c\n", 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17);
        printf("\t1. Encode\n");
        printf("\t2. Decode\n");
        printf("\t0. Exit\n");
        printf(">> ");
        scanf("%d", &fill_data);
        printf("----------------------\n");

        switch (fill_data)
        {
        case 0:
            return;
        case 1:
        {
            fflush(stdin);
            printf("Enter String\n>> ");
            getline(cin, text);

            Node *root = build_tree();
            print_encoded_table();
            encoding_string();
            break;
        }
        case 2:
            fflush(stdin);
            printf("Enter String\n>> ");
            getline(cin, text);

            Node *root = build_tree();
            print_encoded_table();
            decoding_string(root);
            break;
        }
        printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
}

int main()
{
    printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t|Neko941's Huffman Coding Algorithm |\n");
    printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    implementation();

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}
