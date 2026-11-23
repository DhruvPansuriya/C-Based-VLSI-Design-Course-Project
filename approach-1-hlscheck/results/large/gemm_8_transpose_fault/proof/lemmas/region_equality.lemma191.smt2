; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_25 () (_ BitVec 32))
(declare-fun arg0_25 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x63587 (bvmul arg0_25 arg1_25)))
(let ((?x66120 (bvmul (_ bv4294967295 32) ?x63587)))
(let ((?x2183 (bvmul arg0_25 arg1_11)))
(let ((?x63845 (bvadd ?x2183 ?x66120)))
(and (distinct ?x63845 (_ bv0 32)) true))))))
(check-sat)
