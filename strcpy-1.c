char * strcpy ( char * p, char * q )
{
	int i ;

	for ( i = 0 ; i < strlen ( q ) + 1 ; i ++ )
		p [ i ] = q [ i ] ;
	return p ;
}
