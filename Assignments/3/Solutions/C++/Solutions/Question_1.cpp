//Waqas_22i2469

// Assignment # 2

/*
   Muhammad Waqas Shahid Khan
   22I - 2469
   BS SE-E
*/

#include <iostream>

using namespace std;

class Block
{
private:
	string shape;
	string colour;

public:

	// --------------------  BLOCK CONTRUCTOR  --------------------

	Block(string s="\0", string c = "\0")
	{
		shape = s;
		colour = c;
	}

	// --------------------  DISPLAY FUNCTION  --------------------

	ostream& display(ostream& out) const                                          
	{
		int counter = 0;

		while (colour[counter] != '\0')
		{
			counter += 1;
		}

		if (counter != 0)
		{
			out << "-------------------------------" << endl << endl << endl;
			out << "( " << shape << " , " << colour << " ) " << endl << endl << endl ;
		}
		else
		{
			out << "-------------------------------" << endl << endl << endl;
			out << "( " << shape << " ) " << endl << endl << endl;
		}
		return out;
	}

	// --------------------  OVERLOADED OPERATOR << --------------------

	friend ostream& operator<<(ostream & out ,const Block& obj)                                      
	{
		obj.display(cout);
		return out;
	}

	// --------------------  GETTERS SETTERS START --------------------

	string getShape() const                                            
	{
		return shape;
	}

	string getColour() const
	{
		return colour;
	}

	// --------------------  GETTERS SETTERS END --------------------

};

class Build
{
private:
	Block*** content; // i = height = z / j = depth = y / k = width = x
	int height;
	int depth;
	int width;

public:

	// --------------------  BUILD CONTRUCTOR --------------------

	Build(Block& obj)
	{
		height = 1;
		depth = 1;
		width = 1;

		content = new Block **[height];

		for (int i = 0; i < height; i++)
		{
			content[i] = new Block*[depth];

			for (int j = 0; j < depth; j++)
			{
				content[i][j] = new Block[width];
			}
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < depth; j++)
			{
				for (int k = 0; k < width; k++)
				{
					content[i][j][k] = obj;
				}
			}
		}
		/*cout << "HERE"<<endl;
		cout << content[0][0][0]<<endl;*/
	}

	// --------------------  DISPLAY FUNCTION --------------------

	ostream& display(ostream& out) const
	{
		/*cout << height;*/
		if (content != NULL)
		{
			for (int i = 0; i < height; i++)
			{
				cout << "Layer Number " << i+1 <<endl << endl;
				for (int j = 0; j < depth; j++)
				{
					for (int k = 0; k < width; k++)
					{
						cout<<i<<j<<k;
						cout<<content[i][j][k];
					}
				}
			}
		}
		return out;
	}

	// --------------------  OVERLOADED OPERATOR << --------------------

	friend ostream& operator<<(ostream& out, const Build& obj)
	{
		obj.display(cout);
		return out;
	}

	// --------------------  OVERLOADED OPERATOR ^= --------------------

	Build operator ^= (const Build & obj)                                          
	{
		int new_height = this->height + obj.height;
		int new_depth = this->depth + obj.depth -1 ;
		int new_width = this->width + obj.width -1 ;
		/*cout << "New : " << new_height << new_depth << new_width << endl;*/

		Block ***new_content= new Block **[new_height];

		for (int i = 0; i < new_height; i++)
		{
			new_content[i] = new Block * [new_depth];

			for (int j = 0; j < new_depth; j++)
			{
				new_content[i][j] = new Block[new_width];
			}
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < depth; j++)
			{
				for (int k = 0; k < width; k++)
				{
					/*cout << content[i][j][k];*/
					new_content[i][j][k] = content[i][j][k];
				}
			}
		}

		/*cout << "Old : " << height << depth << width << endl;*/
		for (int i = 0; i < obj.height; i++)
		{
			for (int j = 0; j < obj.depth; j++)
			{
				for (int k = 0; k < obj.width; k++)
				{
					/*cout << i << j << k<<endl;*/
					new_content[i+(this->height)][j][k] = obj.content[i][j][k]; //chtzif-----------------------------------------------------------------------------------------------
				}
			}
		}

		// To Check New Content
		//for (int i = 0; i < new_height; i++)
		//{
		//	for (int j = 0; j < new_depth; j++)
		//	{
		//		for (int k = 0; k < new_width; k++)
		//		{
		//			/*cout << i << j << k<<endl;*/
		//			cout<<new_content[i][j][k];
		//		}
		//	}
		//}

		//for (int i = 0; i < new_height; i++)
		//{
		//	for (int j = 0; j < new_depth; j++)
		//	{
		//		for (int k = 0; k < new_width; k++)
		//		{
		//			/*cout << i << j << k << endl;
		//			cout << content[i][j][k] << endl;
		//			cout<<obj.content[i][j][k]<< endl;*/

		//			string check_shape = obj.content[i][j][k].getShape();
		//			int c_s = 0;
		//			while (check_shape[c_s] != '\0')
		//			{
		//				c_s += 1;
		//			}
		//			cout << c_s;
		//			if (i < height && j < depth && k < width)
		//			{
		//				new_content[i][j][k] = content[i][j][k];
		//			}
		//			else if (c_s != 0)
		//			{
		//				new_content[i][j][k] = obj.content[i-height][j-depth][k-width];
		//			}
		//		}
		//	}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < depth; j++)
			{
				delete[] content[i][j];
			}
			delete[] content[i];
		}
		delete[] content;

		this->height = new_height;
		this->depth = new_depth;
		this->width = new_width;

		/*cout << "New Updated : " << height << depth << width << endl;*/

		content = new Block **[height];

		for (int i = 0; i < height; i++)
		{
			content[i] = new Block * [depth];

			for (int j = 0; j < depth; j++)
			{
				content[i][j] = new Block[width];
			}
		}

		// To Copy New_Content to Content
		/*Block rough_obj("NIL", "NIL");*/

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < depth; j++)
			{
				for (int k = 0; k < width; k++)
				{
					/*content[i][j][k] = rough_obj;*/
					content[i][j][k] = new_content[i][j][k];
				}
			}
		}

		// To Deallocate New_Content
		for (int i = 0; i < new_height; i++)
		{
			for (int j = 0; j < new_depth; j++)
			{
				delete[] new_content[i][j];
			}
			delete[] new_content[i];
		}
		delete[] new_content;

		/*cout << "New Updated : " << height << depth << width << endl;*/

		return *this;
	}

	// --------------------  OVERLOADED OPERATOR =- --------------------

	Build operator -= (const Build& obj)
	{
		if (obj.height < this->height)
		{
			cout << "This Action Cannot Be Done" << endl;
			return *this;
		}

		if (obj.height>this->height)
		{
			int new_height = this->height;
			int new_depth = this->depth + obj.depth;
			int new_width = this->width + obj.width - 1;
			/*cout << "New (Greater Height Case): " << new_height << new_depth << new_width << endl;*/


			// -----------  TO CREATE A NEW DMA ARRAY ----------- 

			Block*** new_content = new Block * *[new_height];

			for (int i = 0; i < new_height; i++)
			{
				new_content[i] = new Block * [new_depth];

				for (int j = 0; j < new_depth; j++)
				{
					new_content[i][j] = new Block[new_width];
				}
			}

			// ----------- TO COPY OLD CONTENTS ----------- 

			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < depth; j++)
				{
					for (int k = 0; k < width; k++)
					{
						/*cout << content[i][j][k];*/
						new_content[i][j][k] = content[i][j][k];
					}
				}
			}

			// ----------- TO ADD CONTENTS BEHIND ----------- 
			
			for (int i = height - 1; i < new_height; i++)
			{
				for (int j = 0; j < obj.depth; j++)
				{
					for (int k = 0; k < obj.width; k++)
					{
						/*cout << i << j << k<<endl;*/
						new_content[i][j + (this->depth)][k] = obj.content[i][j][k];
					}
				}
			}

			// ----------- TO CHECK NEW CONTENT ----------- 
			/*for (int i = 0; i < new_height; i++)
			{
				for (int j = 0; j < new_depth; j++)
				{
					for (int k = 0; k < new_width; k++)
					{
						cout << i << j << k<<endl;
						cout << new_content[i][j][k];
					}
				}
			}*/

			// ----------- TO DEALLOCATE OLD CONTENT ----------- 

			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < depth; j++)
				{
					delete[] content[i][j];
				}
				delete[] content[i];
			}
			delete[] content;

			this->height = new_height;
			this->depth = new_depth;
			this->width = new_width;

			/*cout << "New Updated : " << height << depth << width << endl;*/

			// ----------- TO UPDATE OLD CONTENT ----------- 

			content = new Block * *[height];

			for (int i = 0; i < height; i++)
			{
				content[i] = new Block * [depth];

				for (int j = 0; j < depth; j++)
				{
					content[i][j] = new Block[width];
				}
			}

			// ----------- TO COPY NEW_CONTENT TO CONTENT ----------- 

			/*Block rough_obj("NIL", "NIL");*/
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < depth; j++)
				{
					for (int k = 0; k < width; k++)
					{
						/*content[i][j][k] = rough_obj;*/
						content[i][j][k] = new_content[i][j][k];
					}
				}
			}

			// ----------- TO DEALLOCATE  NEW_CONTENT ----------- 

			for (int i = 0; i < new_height; i++)
			{
				for (int j = 0; j < new_depth; j++)
				{
					delete[] new_content[i][j];
				}
				delete[] new_content[i];
			}
			delete[] new_content;

			/*cout << "New Updated : " << height << depth << width << endl;*/

			return *this;
		}

		if (this->height == obj.height)                             //---------------------------------------------------what to do here---------------------------------
		{
			int new_height = this->height;
			int new_depth = this->depth + obj.depth;
			int new_width = this->width + obj.width - 1;
			/*cout << "New (Greater Height Case): " << new_height << new_depth << new_width << endl;*/


			// -----------  TO CREATE A NEW DMA ARRAY ----------- 

			Block*** new_content = new Block * *[new_height];

			for (int i = 0; i < new_height; i++)
			{
				new_content[i] = new Block * [new_depth];

				for (int j = 0; j < new_depth; j++)
				{
					new_content[i][j] = new Block[new_width];
				}
			}

			// ----------- TO COPY OLD CONTENTS ----------- 

			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < depth; j++)
				{
					for (int k = 0; k < width; k++)
					{
						/*cout << content[i][j][k];*/
						new_content[i][j][k] = content[i][j][k];
					}
				}
			}

			// ----------- TO ADD CONTENTS BEHIND ----------- 

			for (int i = height - 1; i < new_height; i++)
			{
				for (int j = 0; j < obj.depth; j++)
				{
					for (int k = 0; k < obj.width; k++)
					{
						/*cout << i << j << k<<endl;*/
						new_content[i][j + (this->depth)][k] = obj.content[i][j][k];
					}
				}
			}

			// ----------- TO CHECK NEW CONTENT ----------- 
			/*for (int i = 0; i < new_height; i++)
			{
				for (int j = 0; j < new_depth; j++)
				{
					for (int k = 0; k < new_width; k++)
					{
						cout << i << j << k<<endl;
						cout << new_content[i][j][k];
					}
				}
			}*/

			// ----------- TO DEALLOCATE OLD CONTENT ----------- 

			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < depth; j++)
				{
					delete[] content[i][j];
				}
				delete[] content[i];
			}
			delete[] content;

			this->height = new_height;
			this->depth = new_depth;
			this->width = new_width;

			/*cout << "New Updated : " << height << depth << width << endl;*/

			// ----------- TO UPDATE OLD CONTENT ----------- 

			content = new Block * *[height];

			for (int i = 0; i < height; i++)
			{
				content[i] = new Block * [depth];

				for (int j = 0; j < depth; j++)
				{
					content[i][j] = new Block[width];
				}
			}

			// ----------- TO COPY NEW_CONTENT TO CONTENT ----------- 

			/*Block rough_obj("NIL", "NIL");*/
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < depth; j++)
				{
					for (int k = 0; k < width; k++)
					{
						/*content[i][j][k] = rough_obj;*/
						content[i][j][k] = new_content[i][j][k];
					}
				}
			}

			// ----------- TO DEALLOCATE  NEW_CONTENT ----------- 

			for (int i = 0; i < new_height; i++)
			{
				for (int j = 0; j < new_depth; j++)
				{
					delete[] new_content[i][j];
				}
				delete[] new_content[i];
			}
			delete[] new_content;

			/*cout << "New Updated : " << height << depth << width << endl;*/

			return *this;
		}

	}

	// --------------------  OVERLOADED OPERATOR += --------------------

	Build operator += (const Build& obj)
	{
		if (obj.height < this->height)
		{
			cout << "This Action Cannot Be Done" << endl;
			return *this;
		}

		if (obj.height >= this->height)
		{
			if (this->depth > obj.depth)
			{
				cout << "This Action Cannot Be Done Because Depth is Smaller!" << endl;
				return *this;
			}

			if (this->depth <= obj.depth)
			{
				int new_height = this->height;
				int new_depth = this->depth;
				int new_width = this->width + obj.width;
				/*cout << "New (Greater Height Case): " << new_height << new_depth << new_width << endl;*/


				// -----------  TO CREATE A NEW DMA ARRAY ----------- 

				Block*** new_content = new Block * *[new_height];

				for (int i = 0; i < new_height; i++)
				{
					new_content[i] = new Block * [new_depth];

					for (int j = 0; j < new_depth; j++)
					{
						new_content[i][j] = new Block[new_width];
					}
				}

				// ----------- TO COPY OLD CONTENTS ----------- 

				for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < depth; j++)
					{
						for (int k = 0; k < width; k++)
						{
							/*cout << content[i][j][k];*/
							new_content[i][j][k] = content[i][j][k];
						}
					}
				}

				// ----------- TO ADD CONTENTS ON THE RIGHT ----------- 

				for (int i = height - 1; i < new_height; i++)
				{
					for (int j = 0; j < obj.depth; j++)
					{
						for (int k = 0; k < obj.width; k++)
						{
							/*cout << i << j << k<<endl;*/
							new_content[i][j][k + (this->width)] = obj.content[i][j][k];
						}
					}
				}

				// ----------- TO CHECK NEW CONTENT ----------- 
				/*for (int i = 0; i < new_height; i++)
				{
					for (int j = 0; j < new_depth; j++)
					{
						for (int k = 0; k < new_width; k++)
						{
							cout << i << j << k<<endl;
							cout << new_content[i][j][k];
						}
					}
				}*/

				// ----------- TO DEALLOCATE OLD CONTENT ----------- 

				for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < depth; j++)
					{
						delete[] content[i][j];
					}
					delete[] content[i];
				}
				delete[] content;

				this->height = new_height;
				this->depth = new_depth;
				this->width = new_width;

				/*cout << "New Updated : " << height << depth << width << endl;*/

				// ----------- TO UPDATE OLD CONTENT ----------- 

				content = new Block * *[height];

				for (int i = 0; i < height; i++)
				{
					content[i] = new Block * [depth];

					for (int j = 0; j < depth; j++)
					{
						content[i][j] = new Block[width];
					}
				}

				// ----------- TO COPY NEW_CONTENT TO CONTENT ----------- 

				/*Block rough_obj("NIL", "NIL");*/
				for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < depth; j++)
					{
						for (int k = 0; k < width; k++)
						{
							/*content[i][j][k] = rough_obj;*/
							content[i][j][k] = new_content[i][j][k];
						}
					}
				}

				// ----------- TO DEALLOCATE  NEW_CONTENT ----------- 

				for (int i = 0; i < new_height; i++)
				{
					for (int j = 0; j < new_depth; j++)
					{
						delete[] new_content[i][j];
					}
					delete[] new_content[i];
				}
				delete[] new_content;

				/*cout << "New Updated : " << height << depth << width << endl;*/

				return *this;
			}
		}
	}

	Build operator *(unsigned int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			(*this) += (*this);
		}

		return *this;
	}

	Build operator /(unsigned int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			(*this) ^= (*this);
		}
		return *this;
	}

	Build operator %(unsigned int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			(*this) -= (*this);
		}
		return *this;
	}

	friend Build operator * (unsigned int n , const Build & obj) 
	{
		Build obj2(obj);

		for (int i = 0 ; i<n-1 ; i++)
		{
			cout << i << endl;
			obj2 += obj2;

			/*cout << i << endl;
			cout << obj2;*/
		}

		return obj2;
	}

	friend Build operator / (unsigned int n, const Build& obj)
	{
		Build obj2(obj);

		for (int i = 0; i < n - 1; i++)
		{
			obj2 ^= obj2;
			/*cout << i << endl;
			cout << obj2;*/
		}

		return obj2;
	}

	friend Build operator % (unsigned int n, const Build& obj)
	{
		Build obj2(obj);

		for (int i = 0; i < n - 1; i++)
		{
			obj2 -= obj2;

			/*cout << i << endl;
			cout << obj2;*/
		}

		return obj2;
	}

	Build operator^ (const Build& obj)
	{
		return ((*this) ^= obj);
	}

	friend Build operator ^ (unsigned int n, const Build& obj)
	{

	}

	Build operator- (const Build& obj)
	{
		return ((*this) -= obj);
	}

	friend Build operator - (unsigned int n, const Build& obj)
	{

	}

	Build operator+ (const Build& obj)
	{
		return ((*this) += obj);
	}

	friend Build operator + (unsigned int n, const Build& obj)
	{

	}
	// --------------------  GETTERS SETTERS START --------------------

	void setHeight(int input)
	{
		height = input;
	}


	int getHeight() const
	{
		return height;
	}

	void setDepth(int input)
	{
		depth = input;
	}

	int getDepth() const
	{
		return depth;
	}

	void setWidth(int input)
	{
		width = input;
	}

	int getWidth() const
	{
		return width;
	}

	// --------------------  GETTERSS SETTERS END --------------------

};

int main()
{
	Block obj0 ("ObliquedR" , "Red");
	Block obj1("ObliquedL", "Green");
	/*obj.display(cout);
	cout << obj;*/


	Build obj00(obj0);
	Build obj11(obj1);

	/*obj00.display(cout);
	obj11.display(cout);*/
	/*cout << obj00;
	cout << obj11;*/

	/*cout << obj00;*/

	/* FOR ^= FIRST INCREASES HEIGHT
	obj00 ^= obj11;*/

	/*obj11 ^= obj11;
	obj11 ^= obj11;*/

	/*obj11 == 411 ijk*/

	/*cout << obj00;*/

	
	/*obj00 ^= obj00;
	obj00 -= obj00;*/

	/*cout << obj00 <<" done" << endl;

	obj00 += obj00;*/


	cout << obj00;

	 /*obj00 = obj00^obj00;
	 obj00 = obj00 - obj00;
	 obj00 = obj00 + obj00;*/

	/* obj00 ^= obj00;
	 obj00 -= obj00;
	 obj00 += obj00;
	 */

	/*obj00 = 2 / obj00;
	obj00 = 2 % obj00;
	obj00 = 2 * obj00;*/

	/*obj00 = obj00 / 2;
	obj00 =  obj00 % 2;
	obj00 =  obj00 * 2;*/

	 cout << obj00;

	/*cout << endl << "Then" << endl;

	cout << obj11;*/

	return 0;
}
