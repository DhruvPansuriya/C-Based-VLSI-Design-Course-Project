; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_17 () (_ BitVec 32))
(assert
 (let ((?x63851 (bvmul arg0_10 arg1_10)))
(let ((?x64252 (bvmul (_ bv4294967295 32) ?x63851)))
(let ((?x45170 (bvmul arg0_10 arg1_17)))
(let ((?x59050 (bvadd ?x45170 ?x64252)))
(and (distinct ?x59050 (_ bv0 32)) true))))))
(check-sat)
