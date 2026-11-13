; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x144 (bvmul arg0_2 arg1_2)))
(let ((?x205 (bvmul (_ bv4294967295 32) ?x144)))
(let ((?x56 (bvmul arg0_2 arg1_8)))
(let ((?x5547 (bvadd ?x56 ?x205)))
(and (distinct ?x5547 (_ bv0 32)) true))))))
(check-sat)
