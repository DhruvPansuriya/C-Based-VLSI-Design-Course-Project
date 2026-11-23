; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x340431 (bvmul arg0_1 arg1_13)))
(let ((?x95552 (bvmul (_ bv4294967295 32) ?x340431)))
(let ((?x501091 (bvmul arg0_1 arg1_7)))
(let ((?x316705 (bvadd ?x501091 ?x95552)))
(and (distinct ?x316705 (_ bv0 32)) true))))))
(check-sat)
