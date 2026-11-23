; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x236431 (bvmul arg0_11 arg2_2)))
(let ((?x392492 (bvmul (_ bv4294967295 32) ?x236431)))
(let ((?x21310 (bvmul arg0_11 arg2_1)))
(let ((?x724991 (bvadd ?x21310 ?x392492)))
(and (distinct ?x724991 (_ bv0 32)) true))))))
(check-sat)
