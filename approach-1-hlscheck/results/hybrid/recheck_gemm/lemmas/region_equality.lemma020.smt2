; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x156 (bvmul arg0_5 arg1_9)))
(let ((?x6041 (bvmul (_ bv4294967295 32) ?x156)))
(let ((?x83 (bvmul arg0_5 arg1_6)))
(let ((?x21979 (bvadd ?x83 ?x6041)))
(and (distinct ?x21979 (_ bv0 32)) true))))))
(check-sat)
