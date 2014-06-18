# if ! defined ( __STACK_H__ )
 
#   define __STACK_H__
 
	struct element {
		int value ;
		struct element * next ;
	} ;
 
	typedef struct element * stack ;
 
	stack new ( ) ;
	int is_empty ( stack ) ;
	stack push ( stack, int ) ;
	stack pop ( stack ) ;
	int top ( stack ) ; 
 
# endif /* __STACK_H__ */
