; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_30 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_51 () (_ BitVec 32))
(assert
 (let ((?x15427 (bvmul arg0_6 arg1_30)))
(let ((?x63911 (bvmul (_ bv4294967295 32) ?x15427)))
(let ((?x63628 (bvmul arg0_6 arg1_51)))
(let ((?x64287 (bvadd ?x63628 ?x63911)))
(and (distinct ?x64287 (_ bv0 32)) true))))))
(check-sat)
