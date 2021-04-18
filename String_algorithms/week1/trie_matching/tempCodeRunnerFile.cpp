int find(trie &t, string &text, int text_i, int tri_i)
{
	int found = 0;
	edges::iterator itr = t[tri_i].begin();
	while(itr!=t[tri_i].end())
	{
		
			if((*itr).first=='$')
			{
				found++;				
			}
			if(text_i<text.size())
			{
				if((*itr).first==text[text_i])
				{
					found+=find(t, text, text_i+1,  (*itr).second);
				}
			}


			
		itr++;
	}
	return found;
	
}