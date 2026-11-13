; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_33 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x63855 (bvmul arg0_9 arg1_33)))
(let ((?x60631 (bvmul (_ bv4294967295 32) ?x63855)))
(let ((?x64032 (bvmul arg0_9 arg1_12)))
(let ((?x75194 (bvadd ?x64032 ?x60631)))
(and (distinct ?x75194 (_ bv0 32)) true))))))
(check-sat)
