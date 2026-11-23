; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x2588 (bvmul arg0_0 arg1_8)))
(let ((?x17989 (bvmul (_ bv4294967295 32) ?x2588)))
(let ((?x123 (bvmul arg0_0 arg1_2)))
(let ((?x101 (bvadd ?x123 ?x17989)))
(and (distinct ?x101 (_ bv0 32)) true))))))
(check-sat)
