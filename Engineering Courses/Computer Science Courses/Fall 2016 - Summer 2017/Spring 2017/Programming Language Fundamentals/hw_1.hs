
--[CS 381] Homework 1 (Abstract Syntax)

-- Author: Rhea Mae V. Edwards
-- Date: 04/25/2017

-- module hw_1 where

import Prelude hiding (Num)

-- Exercise 1. Mini Logo
-- Part (a)
-- [Abstract Syntax for Mini Logo as Haskell data type]

data Cmd = Pen Mode
         | MoveTo Pos Pos
		 | Def Name Pars Cmd
		 | Call Name Vals
		 | Seq [Cmd] 
		 -- Seq Cmd Cmd
		 deriving Show

data Mode = Up | Down

data Pos = Int Num | String Name

type Pars = [Name]

type Vals = [Num]

-- Nonterminals -> Predefined Haskell Types
type Num = Int
type Name = String

-- Instances
instance Show Mode where
	show Up = "Up"
	show Down = "Down"

instance Show Pos where
	show (Int s) = show s

-- Part (b)
-- [Macro Vector that Draws a Line]
-- Move pen from (x1, y1) to (x2, y2)

vector = Def "vector" ["x1", "y1", "x2", "y2"] (Seq [Pen Up, MoveTo (String "x1") (String "y1"), Pen Down, MoveTo (String "x2") (String "y2"), Pen Up])

-- Part (c)
-- [Define steps :: Int -> Cmd that Constructs Stair for n Steps]

steps :: Int -> Cmd
steps s | s < 2 = Seq [Call "vector" [0, 0, 0, 1], Call "vector" [0, 1, 1, 1]]
steps s = Seq [steps (s-1), Seq [Call "vector" [s-1, s-1, s-1, s], Call "vector" [s-1, s, s, s]]]

-- Exercise 2. Digital Circuit Design Language
-- Part (a)
-- [Abstract Syntax for language as Haskell data type]

data Circuit = Circuit Gates Links

data Gates = Gate Int GateFn Gates | EmptyG

data GateFn = And | Or | Xor | Not
              deriving Show

data Links = Link Pair Pair Links | EmptyL 

data Pair = Pair Int Int

-- Part (b)
-- [Half Adder Circuit in Abstract Syntax, Haskell Data Type Value]
-- 1:xor;
-- 2:and;
-- from 1.1 to 2.1;
-- from 1.2 to 2.2;

halfadder = Circuit (Gate 1 Xor (Gate 2 And EmptyG)) 
					(Link (Pair 1 1) (Pair 2 1)
					(Link (Pair 1 2) (Pair 2 2)
					 EmptyL))

-- Part (c)
-- [Haskell Function that Implements Pretty Printer for Abstract Syntax]

printp :: Pair -> String
printp (Pair a b) = show a ++ "." ++ show b

printg :: Gates -> String
printg EmptyG = ""
printg (Gate n gatefn gates) = show n ++ ":" ++ show gatefn ++ ";\n" ++ printg gates

printl :: Links -> String
printl EmptyL = ""
printl (Link p1 p2 links) = "from " ++ printp p1 ++ " to " ++ printp p2 ++ ";\n" ++ printl links

pprint :: Circuit -> String
pprint (Circuit gates links) = printg gates ++ printl links

-- Exercise 3. Designing Abstract Syntax

data Expr = N Int
		  | Plus Expr Expr
		  | Times Expr Expr
		  | Neg Expr

-- Alternative
data Op = Add | Multiply | Negate
		deriving Show

data Exp = Num Int
		 | Apply Op [Exp]
		 deriving Show

-- Part (a)
-- [Expression -(3+4)*7 in Alternative Abstract Syntax]

expr = Apply Multiply [Apply Negate [Apply Add [Num 3, Num 4]], Num 7]

-- Part (b)
-- [Advantages or Disadvantages of Either Representation]

{-- 
The advantage of the alternative expression, is that it seems to be more straightforward
in the way that you would apply an operation to another operation, working from the outside
in, and then apply numbers on the way, until you reach a valid expression. The pathway in
creating a valid expression seems to be more direct, where you can add numbers at any point 
apply it to the following operations or any before.
The initial expression serves the same idea, but also have the simarlies in the statements,
and also having to choose an operation first and then deciding where in the statement, either
an operation or a number the user would like to add next into the expression, also is direct 
and easy to understand in its own, being an advangtage, depending on the prefrence of the user.
Every statement within the initially representation, appears to be more as a pair of a part of
any expression that being created.
--}

-- Part (c)
-- [Function translate :: Expr -> Exp]
-- Translates expressions given first abstract syntax into equivalent expressions in secodn abstract syntax

translate :: Expr -> Exp
translate (N a) = (Num a)
translate (Plus a b) = Apply Add [translate a, translate b]
translate (Times a b) = Apply Multiply [translate a, translate b]
translate (Neg a) = Apply Negate [translate a]

-- To complie within ghci interpreter...
-- :load hw_1.hs
