; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x5586 (bvmul arg0_13 arg2_5)))
(let ((?x722378 (bvmul (_ bv4294967295 32) ?x5586)))
(let ((?x21575 (bvmul arg0_13 arg2_4)))
(let ((?x725617 (bvadd ?x21575 ?x722378)))
(and (distinct ?x725617 (_ bv0 32)) true))))))
(check-sat)
